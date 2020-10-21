. .\project_paths.ps1

if (Test-Path -Path $DEPS_DIR)
{
    Remove-Item $DEPS_DIR -Recurse -Force
    Write-Output "Successfully deleted: ${DEPS_DIR}"
}
else
{
    Write-Output "${DEPS_DIR} does not exist"
}
