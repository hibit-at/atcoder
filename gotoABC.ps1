param (
    [int]$number
)

if (-not $number) {
    Write-Host "Please specify a number as an argument."
    exit
}

# Determine the subdirectory by dividing by 100
$dirnum = [math]::Floor($number / 100)
$subdir = "ABC$($dirnum)00-$($dirnum)99"

# Create the target directory path relative to the script location
$targetDir = Join-Path -Path $PSScriptRoot -ChildPath "ABC\$subdir\ABC$number"

# Check if the directory exists and move there
if (Test-Path $targetDir) {
    Set-Location $targetDir
    Write-Host ("ABC{0} moved to {1}" -f $number, $targetDir)
} else {
    Write-Host ("ABC{0} does not exist" -f $number)
}
