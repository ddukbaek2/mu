# utf8BOM
# utf8
Get-ChildItem -Path "." -Recurse -Include *.c, *.h | ForEach-Object {
#	$content = Get-Content $_.FullName -Raw
#	Set-Content $_.FullName -Value $content -Encoding utf8BOM

	# utf8BOM�� ���� 6.0 ���� �Ŀ���.
	# ���� ������ ù 3����Ʈ �о BOM Ȯ��.
	$firstBytes = [byte[]](Get-Content $_.FullName -Encoding Byte -TotalCount 3)
	$hasBOM = ($firstBytes.Length -eq 3 -and $firstBytes[0] -eq 0xEF -and $firstBytes[1] -eq 0xBB -and $firstBytes[2] -eq 0xBF)

	if (-not $hasBOM) {
		# UTF-8 BOM ����Ʈ �迭.
		$bom = [byte[]]@(0xEF, 0xBB, 0xBF)

		# ���� ���� ��������. (UTF-8 ���ڵ�)
		$content = Get-Content $_.FullName -Raw
		$utf8Bytes = [System.Text.Encoding]::UTF8.GetBytes($content)

		# BOM�� ���� �����Ͽ� ���Ͽ� ����.
		[System.IO.File]::WriteAllBytes($_.FullName, $bom + $utf8Bytes)

		Write-Host "Updated: $($_.FullName)"
	} else {
		Write-Host "Skipped (already UTF-8 BOM): $($_.FullName)"
	}
}