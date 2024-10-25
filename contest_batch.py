from pathlib import Path

def create_contest_directory(base_dir, contest_number):
    """指定したコンテスト番号のディレクトリを作成し、必要なファイルを追加します。"""
    lower = contest_number // 100 * 100
    upper = lower + 99
    middle_folder_name = f'ABC{lower}-{upper}'
    contest_dir = base_dir / middle_folder_name / f'ABC{contest_number}'

    # 中間ディレクトリが存在しない場合は作成
    contest_dir.mkdir(parents=True, exist_ok=True)

    return contest_dir

def create_files(directory, file_names):
    """指定されたディレクトリにファイルを作成します。"""
    for file_name in file_names:
        (directory / file_name).touch()

def main():
    print('input the number of the next contest')
    n = int(input())

    base_dir = Path('ABC')
    contest_dir = create_contest_directory(base_dir, n)

    file_names = [
        '_a.cpp',
        '_a.py',
        'b.cpp',
        'c.cpp',
        'd.cpp',
        'e.cpp',
        'input.txt',
    ]

    create_files(contest_dir, file_names)
    print(f'Created directory and files for ABC{n}.')

if __name__ == '__main__':
    main()
