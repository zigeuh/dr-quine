def main():
    str = 'def main():\n    str = %r\n    print(str %% str)\n\nif __name__ == "__main__":\n    main()'
    print(str % str)

if __name__ == "__main__":
    main()
