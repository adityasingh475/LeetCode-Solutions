
class ProductOfNumbers {
    vector<int> pref;

public:
    ProductOfNumbers() {
        pref.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            pref.clear();
            pref.push_back(1);
        } else {
            pref.push_back(pref.back() * num);
        }
    }

    int getProduct(int k) {
        int n = pref.size();

        if (k >= n) return 0;

        return pref[n - 1] / pref[n - 1 - k];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna