#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include<fstream>

using namespace std;
//To make the circular buffer accept all data types, using Template class
template <class T>
class CircularBuffer
{
  public:
    explicit CircularBuffer(size_t size) :
        buffer_(std::unique_ptr<T[]>(new T[size])),
        max_size_(size)
        {

        }
    bool readBytesFromFile(const std::string filename, T& bytes);

    //Function to write data to buffer_
    void writeBytesToBuffer(T bytes);

    // Function to read data from buffer_
    T readBytesFromBuffer();
    bool writeBytesToFile(const std::string filename, const T& bytes);

    void resetBuffer();
    bool isBufferEmpty() const;
    bool isBufferFull() const;
    size_t bufferCapacity() const;
    size_t bufferSize() const;

  private:
  	std::mutex mutex_;
	std::unique_ptr<T[]> buffer_;
	size_t head_ = 0;
	size_t tail_ = 0;
	const size_t max_size_;
	mutable bool isbufferfull_ = 0;
};
