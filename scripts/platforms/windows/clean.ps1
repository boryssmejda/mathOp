. .\project_paths.ps1

function Remove-IfExists {
    param (
        [Parameter(Mandatory)]
        [string]$FOLDER_NAME
    )

    if (Test-Path -Path $FOLDER_NAME)
    {
        Remove-Item $FOLDER_NAME -Recurse -Force
        Write-Output "Successfully deleted: ${FOLDER_NAME}"
    }
    else
    {
        Write-Output "${FOLDER_NAME} does not exist"
    }
}

Remove-IfExists($BUILD_DIR)
Remove-IfExists($INSTALL_DIR)
