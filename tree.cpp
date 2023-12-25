#include <iostream>

// Struktur simpul pohon
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambahkan simpul ke pohon
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Fungsi untuk mencari simpul dalam pohon
TreeNode* search(TreeNode* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

// Fungsi untuk mencari nilai terkecil dalam pohon
TreeNode* minValueNode(TreeNode* root) {
    TreeNode* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Fungsi untuk menghapus simpul dari pohon
TreeNode* remove(TreeNode* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = remove(root->left, value);
    } else if (value > root->data) {
        root->right = remove(root->right, value);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }

    return root;
}

// Fungsi untuk menghapus seluruh pohon
void destroyTree(TreeNode* root) {
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

int main() {
    // Contoh penggunaan pohon biner
    TreeNode* root = nullptr;

    // Menambahkan simpul ke pohon
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Mencari simpul dalam pohon
    std::cout << "Cari 30: " << (search(root, 30) ? "Ditemukan" : "Tidak ditemukan") << std::endl;

    // Menghapus simpul dari pohon
    root = remove(root, 20);
    root = remove(root, 70);

    // Mencari simpul setelah penghapusan
    std::cout << "Cari 20: " << (search(root, 20) ? "Ditemukan" : "Tidak ditemukan") << std::endl;

    // Menghapus seluruh pohon
    destroyTree(root);

    return 0;
}
