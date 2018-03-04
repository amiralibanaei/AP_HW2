#include<iostream>

void sortit(double* sequence, size_t N);

int main() {
  
  size_t n{0};
  double* seq{new double[n]};
  double* copy{};
  double num{};
  
  std::cout << "Please enter the numbers: " << std::endl;
  std::cin >> num;
  if (num == 0) {
    std::cout << "Sequence not created." << std::endl;
    return 0;
  }
  while ( num != 0) {
    copy = new double[n];
    for(size_t i{}; i < n; i++)
      copy[i] = seq[i];
    n++;
    delete[] seq;
    seq = new double[n];
    for(size_t i{}; i < n-1; i++)
      seq[i] = copy[i];
    seq[n-1] = num;
    delete[] copy;

    std::cin >> num;
    if (num == 0)
      std::cout << "Sequence created with " << n << " arguments" << std::endl;
  }

  sortit(seq, n);
  std::cout << "The sorted sequence is:" << std::endl;
  for (size_t i{}; i < n; i++)
    std::cout << seq[i] << std::endl;

  delete[] seq;
  return 0;
}

void sortit(double* sequence, size_t N){
  double temp{};
  for (size_t i{}; i < N; i++)
    for (size_t j{i+1}; j < N; j++)
      if (sequence[j] < sequence[i]) {
	temp = sequence[i];
	sequence[i] = sequence[j];
	sequence[j] = temp;
      }
}
