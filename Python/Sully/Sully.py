import os

def main():
    str = 'import os\n\ndef main():\n    str = {str!r}\n    count = {count}\n    if count == 0: return\n    count -= 1\n    name = f"Sully{{count}}.py"\n    with open(name, "w") as file:\n        file.write(str.format(count=count, str=str))\n    os.system(f"python3 {{name}}")\n\nif __name__ == "__main__":\n    main()\n'
    count = 5
    if count == 0: return
    count -= 1
    name = f"Sully{count}.py"
    with open(name, "w") as file:
        file.write(str.format(count=count, str=str))
    os.system(f"python3 {name}")

if __name__ == "__main__":
    main()
