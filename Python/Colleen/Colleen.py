'''
This is a comment outside the main function
'''
def useless():
    if 0 == 0:
        return 1
    else:
        return 0

def main():
    '''
    This is a comment inside the main function
    '''
    str = '\'\'\'\nThis is a comment outside the main function\n\'\'\'\ndef useless():\n    if 0 == 0:\n        return 1\n    else:\n        return 0\n\ndef main():\n    \'\'\'\n    This is a comment inside the main function\n    \'\'\'\n    str = %r\n    print(str %% str)\n\nif __name__ == "__main__":\n    main()'
    print(str % str)

if __name__ == "__main__":
    main()
