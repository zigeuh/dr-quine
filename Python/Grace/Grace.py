'''
This is a comment
'''
FILENAME = "Grace_kid.py"
STR = '\'\'\'\nThis is a comment\n\'\'\'\nFILENAME = "Grace_kid.py"\nSTR = %r\n\ndef main():\n    with open(FILENAME, "w") as file:\n        file.write(STR %% STR)\n\nif __name__ == "__main__":\n    main()\n'

def main():
    with open(FILENAME, "w") as file:
        file.write(STR % STR)

if __name__ == "__main__":
    main()
