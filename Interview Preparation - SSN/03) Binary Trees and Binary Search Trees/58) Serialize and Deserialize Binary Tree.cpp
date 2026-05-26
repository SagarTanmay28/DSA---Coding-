Serialization is the process of converting a data structure or object into a 
sequence of bits so that it can be stored in a file or memory buffer, or
transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no 
restriction on how your serialization/deserialization algorithm should work. 
  You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes
a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.



class Codec {
public:

    // ---------- SERIALIZE ----------

    void serializeHelper(TreeNode* root, string &s) {

        if(root == NULL){
            s += "N ";
            return;
        }

        s += to_string(root->val) + " ";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s = "";

        serializeHelper(root, s);

        return s;
    }


    // ---------- DESERIALIZE ----------

    TreeNode* buildTree(vector<string>& v, int &i){

        if(v[i] == "N"){
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(v[i]));
        i++;

        root->left = buildTree(v, i);
        root->right = buildTree(v, i);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);

        string temp;

        vector<string> v;

        // SAME TEMPLATE YOU USE
        while(ss >> temp){
            v.push_back(temp);
        }

        int i = 0;

        return buildTree(v, i);
    }
};
