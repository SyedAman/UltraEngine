template <typename T>
void Swap(T& Current, T& Parent)
{
    T Temp = Current;
    Current = Parent;
    Parent = Temp;
}

template <typename T>
struct Less
{
    bool operator()(const T& Left, const T& Right) const
    {
        return Left < Right;
    }
};