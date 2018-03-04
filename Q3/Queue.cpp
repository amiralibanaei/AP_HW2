#include<iostream>
#include<fstream>
#include"Queue.h"

Queue::Queue(std::string filename) : FileName{filename} {

  //Reading the file and finding the number of elements in the queue
  std::ifstream QueueFile;
  QueueFile.open(FileName);
  std::string dataline;
  getline(QueueFile, dataline);
  N = std::stoi( dataline );
  if (N > 0) {
    empty_flag = false;
    queue = new double[N] {};
  } else {
    std::cout << "ERROR: Cannot make a queue from this file." << std::endl;
    return;
  }

  //Reading the second line of the given file
  getline(QueueFile, dataline);
  size_t start { dataline.find_first_not_of(",") };
  size_t end {};

  //Extracting the elements of the queue from the second line of the file
  while (start != std::string::npos) {
    end = dataline.find_first_of(",", start + 1);
    if (end == std::string::npos)
      end = dataline.length();
    queue[w_index] = std::stod( dataline.substr(start, end-start) );
    w_index++;
    if (w_index == N) {
      w_index = 0;
      full_flag = true;
      break;
    }
    start = dataline.find_first_not_of(",", end + 1);
  }
  
}

Queue::~Queue() {
  delete[] queue;
}

void Queue::displayQueue() {
  if (empty_flag) {
    std::cout << "\nThis queue is empty" << std::endl;
    return;
  } else if (full_flag) {
    std::cout << "\nThis queue is full and its elements are:" << std::endl;
    for (int i{}; i<N; i++){
      if (r_index + i >= N)
	std::cout << queue[r_index + i - N] << std::endl;
      else
	std::cout << queue[r_index + i] << std::endl;
    }
  } else {
    std::cout << "\nThere are " << w_index - r_index << " elements in the ";
    std::cout << N << " spaces of this queue" << std::endl;
    std::cout << "These elements are:" << std::endl;
    int i{r_index};
    while (i != w_index) {
      std::cout << queue[i] << std::endl;
      i++;
      if (i == N)
	i = 0;
    }
  }
  
  std::cout << std::endl;
}

void Queue::enQueue(double x) {
  empty_flag = false;
  if (full_flag) {
    std::cout << "The queue is full, cannot add another element.\n" <<std::endl;
    return;
  } else {
    queue[w_index] = x;
    w_index++;
    if (w_index == N)
      w_index = 0;
    if (w_index == r_index)
      full_flag = true;
  }
}

double Queue::deQueue() {
  full_flag = false;
  if (empty_flag) {
    std::cout << "\n ERROR: The queue is empty.\n" << std::endl;
    return 0;
  } else {
    double value{queue[r_index]};
    r_index++;
    if (r_index == N)
      r_index = 0;
    if (r_index == w_index)
      empty_flag = true;
    return value;
  }
}
