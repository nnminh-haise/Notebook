
# Buffer in file's stream

---

## Example

Managing the process of data enter into the file and handling if the process is successfull or not, including the process of file's manipulation.

> 💡 **Solution:** Use a stream instead of do the handwork.

Normally, we work with stream but we don't really understand how it's actually work.

```cpp
ofstream file ("data.txt"); //* Object of output file stream
file << "James"; //* Transfer data into the file.
file.close(); //* Close the stream.
```

## File's operations

Normally, file's operations are "expensive". It takes more time to access the file than the memory. And maybe we don't have to access the file all the time. So to improve this buffer is come into place.

> Buffer is a part of the computer's memory, and temperary storing data for file handling.

[source](https://stackoverflow.com/questions/33874548/c-what-is-the-need-of-both-buffer-and-stream)
