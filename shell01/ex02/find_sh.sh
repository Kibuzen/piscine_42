find . | grep ".sh" | cut -c3- | cut -d '.' -f1 | sed "s/.*\///g"
