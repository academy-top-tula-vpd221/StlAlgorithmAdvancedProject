#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class User
{
    string name;
    int age;
public:
    string& Name() { return name; }
    int& Age() { return age; }
    User(string name, int age)
        : name{ name }, age{ age } {}

    friend ostream& operator<<(ostream& out, const User& u)
    {
        out << "name: " << u.name << ", age: " << u.age;
        return out;
    }
    friend bool operator<(const User& u1, const User& u2)
    {
        return u1.name < u2.name && u1.age < u2.age;
    }
};

template <class Iterator>
void sortQuick(Iterator begin, Iterator end)
{
    if (begin == end)
        return;
    int pivot = *(begin + distance(begin, end) / 2);
    auto itLeft = partition(begin, end, [pivot](auto item) { return item < pivot; });
    auto itRight = partition(itLeft, end, [pivot](auto item) { return item <= pivot; });
    sortQuick(begin, itLeft);
    sortQuick(itRight, end);
}

template <class Iterator>
void sortHeap(Iterator begin, Iterator end)
{
    auto last = end;
    while (last != begin)
    {
        make_heap(begin, last);
        last--;
        swap(*begin, *last);
    }
}

struct UserAgeComparer
{
    bool operator()(User u1, User u2)
    {
        return u1.Age() < u2.Age();
    }
};

int main()
{
    vector<User> users;
    users.push_back(User("Tim", 32));
    users.push_back(User("Bob", 19));
    users.push_back(User("Jim", 41));
    users.push_back(User("Tom", 27));
    users.push_back(User("Leo", 39));
    users.push_back(User("Sam", 18));

    
    vector<int> v1{ 1, 2, 3, 4, 5, 4, 7 };
    //vector<int> v2{ 11, 22, 33 };

    //auto it = copy_if(v1.begin(), v1.end(), back_inserter(v2), [](auto item) { return item % 2; });
    ////for (auto item : v2) cout << item << " ";
    //copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    //cout << "\n";

    /*srand(time(nullptr));
    vector<int> vrand(10);
    generate(vrand.begin(), vrand.end(), []() { return rand() % 100; });
    copy(vrand.begin(), vrand.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    sortQuick(vrand.begin(), vrand.end());
    copy(vrand.begin(), vrand.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";*/

    //for (User user : users) cout << user << "\n";
    //cout << "\n";
    ////sort(users.begin(), users.end(), [](User u1, User u2) { return u1.Name() < u2.Name(); });
    //sort(users.begin(), users.end(), UserAgeComparer());
    //for (User user : users) cout << user << "\n";
    //cout << "\n";

    /*srand(time(nullptr));
    vector<int> vrand(10);
    vector<int> vcopy;
    generate(vrand.begin(), vrand.end(), []() { return rand() % 100; });
    copy(vrand.begin(), vrand.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    copy(vrand.begin(), vrand.end(), back_inserter(vcopy));

    sort(vrand.begin(), vrand.begin() + 5);
    partial_sort(vcopy.begin(), vcopy.begin() + 5, vcopy.begin() + 5);

    copy(vrand.begin(), vrand.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(vcopy.begin(), vcopy.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";*/

    /*vector<int> heap{ 30, 25, 20, 19, 18, 15, 17, 10, 12, 16 };
    cout << boolalpha << is_heap(heap.begin(), heap.end()) << "\n";*/

    srand(time(nullptr));
    vector<int> vrand(10);
    generate(vrand.begin(), vrand.end(), []() { return rand() % 100; });
    copy(vrand.begin(), vrand.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    sortHeap(vrand.begin(), vrand.end());

    copy(vrand.begin(), vrand.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}
