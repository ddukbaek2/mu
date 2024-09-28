# utf8BOM
# utf8
Get-ChildItem -Path "." -Recurse -Include *.c, *.h | ForEach-Object {
#	$content = Get-Content $_.FullName -Raw
#	Set-Content $_.FullName -Value $content -Encoding utf8BOM

	# utf8BOM이 없는 6.0 이하 파워쉘.
	# 파일 내용의 첫 3바이트 읽어서 BOM 확인.
	$firstBytes = [byte[]](Get-Content $_.FullName -Encoding Byte -TotalCount 3)
	$hasBOM = ($firstBytes.Length -eq 3 -and $firstBytes[0] -eq 0xEF -and $firstBytes[1] -eq 0xBB -and $firstBytes[2] -eq 0xBF)

	if (-not $hasBOM) {
		# UTF-8 BOM 바이트 배열.
		$bom = [byte[]]@(0xEF, 0xBB, 0xBF)

		# 파일 내용 가져오기. (UTF-8 인코딩)
		$content = Get-Content $_.FullName -Raw
		$utf8Bytes = [System.Text.Encoding]::UTF8.GetBytes($content)

		# BOM과 내용 결합하여 파일에 쓰기.
		[System.IO.File]::WriteAllBytes($_.FullName, $bom + $utf8Bytes)

		Write-Host "Updated: $($_.FullName)"
	} else {
		Write-Host "Skipped (already UTF-8 BOM): $($_.FullName)"
	}
}