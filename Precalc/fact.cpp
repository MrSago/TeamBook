
template <int N>
struct fact {
    int arr[N + 1];
    constexpr fact() : arr() {
        arr[0] = 1;
        for (int i = 1; i <= N; i++) {
            arr[i] = (int)(arr[i - 1] * 1ll * i % MOD);
        }
    }
};

