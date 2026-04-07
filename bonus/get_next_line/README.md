*This project has been created as part
of the 42 curriculum by samrazaf*

# Description
The get_next_line function reads and returns a single line from a given file descriptor each time it is called.
A line is defined as a sequence of characters ending with a newline character (\n) or the end of the file (EOF). The function ensures that each call returns the next line in the file, without losing any data between calls.
To achieve this, get_next_line uses an internal buffer to store leftover data from previous reads, allowing it to handle cases where a line is split across multiple reads. This makes the function efficient and suitable for reading large files or streams without loading the entire content into memory.
It is designed to work with any valid file descriptor, including files, standard input, or other input streams, and can be extended to support multiple file descriptors simultaneously.

# Instructions

*The present project functions as a principle of a function that we call in our projects. To do this, we simply need to include the header.h file and we can use the function.*

Below is a fairly simple example of use with a main function.

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h" // HERE WE INCLUDE DE GNL FUNCTION TO BE A PART OF OUR PROJECT

int	nain(void)
{
	int		fd;
	char	*line;

	fd = open("/path/to_the/txt_file.txt", O_RDONLY);
	/* 0_RDONLY represent flag that tell to the syste to only
	* read into the file and not write or add anything in it. */
	if (!fd || fd < -1) // this is a simple security implementation to prevent any issues while opening the file
		printf("Erreur de lecture du fichier");

	line = get_next_line(fd); // HERE WE CAN SEE HOW TO USE THE GNL FUNCTION

	printf("First line:%s", line);

	free(line);
	close(fd);

	return (0);
}
```

# Resources

First of all, to carry out this project, we consulted our peers. This was the first theoretical basis we had. We discussed several studies on how they would do it.

Secondly, to acquire the necessary theoretical knowledge, we watched several [Youtube](https://www.youtube.com) videos on the definition, usefulness, and possibilities of managing static variables that survive the end of a function call. We also consulted the [man page](https://manpages.ubuntu.com/manpages/resolute/en/man2/read.2.html) to review the **read** and **open** functions and file descriptors.


## A detailed description of each utils function

*`get_next_line`: The main function, Reads and returns the next line from a file descriptor. It uses a static variable to keep track of leftover data between calls. The function reads from the file descriptor using read_line, extracts the next line with extract_new_line, updates the remaining data with update_last_line, and returns the extracted line. If the end of file is reached and there is no data left, it returns NULL.

*`ft_strlen`: Calculates the length of a string by counting the number of characters until the null terminator. If the input is NULL, it returns 0.

*`ft_strjoin`: Allocates and returns a new string that is the concatenation of two given strings. If one of the strings is NULL, it returns the other string. If both are NULL, it returns NULL. The returned string must be freed after use.

*`ft_strchr`: Searches for the first occurrence of a character in a string. It returns a pointer to the character if found, or NULL if the character does not exist in the string. The search also includes the null terminator.

*`ft_strdup`: Allocates a new string and copies the content of the given string into it. The newly allocated string must be freed by the caller. Returns NULL if memory allocation fails.

*`ft_substr`: Creates a new string that is a substring of the given string, starting from a specified index and with a maximum specified length. If the starting index is greater than the string length, it returns an empty string. Returns NULL if memory allocation fails.

*`read_line`: Reads data from a file descriptor into a buffer until a specified character (e.g., newline) is found or the end of the file is reached. If the input string is NULL, it initializes it with the buffer contents. Otherwise, it appends the buffer to the existing string. Returns the updated string, or NULL if a read error occurs.

*`extract_new_line`: Extracts a substring from the input string that includes all characters up to and including a specified character (e.g., newline). The resulting string represents the next line to be returned.

*`update_last_line`: Updates the remaining portion of a string after extracting a line. It creates a substring starting immediately after the specified character to preserve any leftover data for the next call. Frees the original string and returns the updated remainder, or NULL if there is no remaining data.
