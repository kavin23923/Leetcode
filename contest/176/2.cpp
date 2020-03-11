class ProductOfNumbers {
public:
  ProductOfNumbers() {
  
  }

  void add(int num) {
    int size = product.size();
    if (size == 0 || product[size - 1] == 0) {
      zero = size;
      product.push_back(num);
    } else {
      product.push_back(product[size - 1] * num);
    }
  }

  int getProduct(int k) {
    int size = product.size();
    if (size - k < zero) {
      return 0;
    } else if (size - k == zero || size - k == 0) {
      return product[size - 1];
    } else {
      return product[size - 1] / product[size - k - 1];
    }
  }
private:
  vector<int> product;
  int zero;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
