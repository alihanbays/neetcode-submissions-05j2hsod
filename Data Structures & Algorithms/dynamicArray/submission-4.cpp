class DynamicArray {
private:
    int* arr;
    int l;
    int c;
public:

    DynamicArray(int capacity) {
        arr = new int[capacity];
        l = 0;
        c = capacity;
    }

    int get(int i) {
        if (i >= 0 && i < l) {
            return arr[i];
        }
    }

    void set(int i, int n) {
        if (i >= 0 && i < l) {
            arr[i] = n;
        }
    }

    void pushback(int n) {
        if (l < c) {
            arr[l] = n;
        } else {
            resize();
            arr[l] = n;
        }
        l++;
    }

    int popback() {
        int tmp = get(l-1);
        set(l-1, 0);
        l--;
        return tmp;
    }

    void resize() {
        c *= 2;
        int* newArr = new int[c];

        for (int i = 0; i < l; i++) {
            newArr[i] = arr[i];
        }
        arr = newArr;
    }

    int getSize() {
        return l;
    }

    int getCapacity() {
        return c;
    }
};
