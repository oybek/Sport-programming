
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>

using namespace std;

#define word_sep(c) ((c == ' ') || (c == ';') || \
					 (c == ',') || (c == ':') || \
					 (c == '-') || (c == '\n'))

#define sent_sep(c) ((c == '.') || (c == '?') || \
					 (c == '!'))

int count_err(string & word, bool first_in_sent)
{
	for (int i = 0; i < word.size(); ++i)
		if (isdigit(word[i]))
			return 0;

	int err = 0;

	if (first_in_sent)
		if (islower(word[0]))
			++err;
	for (int i = 1; i < word.size(); ++i)
		if (isupper(word[i]))
			++err;

	return err;
}

int main()
{
	int c, err_num;
	bool first_word = true;
	string word;

	while ((c = getchar()) != EOF) {
		if (sent_sep(c) || word_sep(c)) {

			err_num += count_err(word, first_word);

			word.erase();
			first_word = false;

			if (sent_sep(c))
				first_word = true;
		}
		else
			word.push_back(c);
	}
	err_num += count_err(word, first_word);

	printf("%d\n", err_num);

	return 0;
}

