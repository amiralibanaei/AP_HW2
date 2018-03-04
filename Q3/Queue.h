#include<string>
class Queue {
 public:
  Queue(std::string filename);
  ~Queue();
  void displayQueue();
  void enQueue(double x);
  double deQueue();
  
 private:
  std::string FileName;
  int N;
  double* queue;
  int r_index{};
  int w_index{};
  bool empty_flag{true};
  bool full_flag{false};
  
};
