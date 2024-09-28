# utf8BOM
# utf8
Get-ChildItem -Path "." -Recurse -Include *.c, *.h | ForEach-Object {
#	$content = Get-Content $_.FullName -Raw
#	Set-Content $_.FullName -Value $content -Encoding utf8BOM

	# utf8BOM이 없는 6.0 이하 파워쉘.
	# 파일 내용의 첫 3바이트 읽어서 BOM 확인.
	$firstBytes = [byte[]](Get-Content $_.FullName -Encoding Byte -TotalCount 3)
	$hasBOM = ($firstBytes.Length -eq 3 -and $firstBytes[0] -eq 0xEF -and $firstBytes[1] -eq 0xBB -and $firstBytes[2] -eq 0xBF)

	if ($hasBOM) {
		# UTF-8 BOM 바이트 배열.
		$bom = [byte[]]@(0xEF, 0xBB, 0xBF)

		# 파일 내용 가져오기. (UTF-8로 읽되 BOM은 제거)
		$content = Get-Content $_.FullName -Raw -Encoding UTF8

		# BOM 제거하고 파일에 쓰기.
		Set-Content $_.FullName -Value $content -Encoding UTF8

		Write-Host "Updated: $($_.FullName)"
	} else {
		Write-Host "Skipped (already UTF-8 BOM): $($_.FullName)"
	}
}