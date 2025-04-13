#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        if (a->freq == b->freq)
            return a->ch > b->ch; // Ensure lexicographical order if frequency is same
        return a->freq > b->freq; // Min-heap based on frequency
    }
};

// Recursive function to generate Huffman codes
void encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Build Huffman Tree
void buildHuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Ensure stable merging by setting internal nodes with a lexicographically smaller char
        char minChar = min(left->ch, right->ch);
        Node *newNode = new Node(minChar, left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    encode(pq.top(), "", huffmanCode);

    // Output Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto &pair : huffmanCode)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}

int main()
{
    string text = "BBBCAAADEEEABBBACCDA";
    buildHuffmanTree(text);
    return 0;
}
