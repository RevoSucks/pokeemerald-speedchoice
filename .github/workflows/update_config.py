import sys


def main():
    template_fn = sys.argv[1]
    replacement_fn = sys.argv[2]

    with open(replacement_fn) as fp:
        replacement_lines = list(fp)

    with open(template_fn) as fp:
        template_lines = list(fp)

    header_line_nos = [i for i, x in enumerate(template_lines) if x.startswith('[')]
    header_line_nos.append(len(template_lines))
    for n, i in enumerate(header_line_nos[:-1]):
        for j in range(i + 1, header_line_nos[n + 1]):
            if '=' in template_lines[j]:
                key, value = [x.strip() for x in template_lines[j].strip().split('=', 1)]
                if key == 'Game' and value == 'MBDN':
                    break
        else:
            continue
        break
    else:
        raise ValueError('Did not find INI entry for Fire Red Speedchoice MBDN')

    template_lines = template_lines[:i] + replacement_lines + template_lines[header_line_nos[n + 1]:]

    with open(template_fn, 'w') as ofp:
        for line in template_lines:
            ofp.write(line)


if __name__ == '__main__':
    main()
