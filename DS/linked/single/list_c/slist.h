typedef struct list List;

List* makeList();
void delList(List*);

void addFirst(int, List*);
void addLast(int, List*);
void addAt(int, int, List*);
void del(int, List*);
void reverse(List*);
List* addLists(List*,List*);
List* subLists(List*,List*);
List* mulLists(List*,List*);

void detectLoop(List*);
void removeLoop(List*);
int length(List*);

void listMid(List*);
void makeLoop(List*);

void display(List*);
