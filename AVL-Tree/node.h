using namespace std;
struct node {
    node* parent;
    node* right;
    node* left;
    int elem;

    // TODO paste your height method here
    int height() {
	
    if(!left && !right){
    return 0;
    }
    if(!right){
        return 1+ left->height();
    }
    if(!left){
        return 1+right->height();
    }
    else{
    return 1 + max(left->height(), right->height());
    }
    }
};
