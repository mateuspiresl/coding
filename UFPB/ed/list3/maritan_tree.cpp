typedef struct s_Node {
	int value;
	int balance;
	struct _Node* left;
	struct _Node* right;
} ps_Node;

typedef ps_Node* Node;

// Insere um nó em uma árvore AVL
// Retorna 1 se a inserção for com sucesso
// Retorna 0, caso contrário
int insert(Node* node, int value)
{
	int ok;

	// Arvore vazia
	if (*node == NULL)
	{
		*node = new tNo;

		(*node)->value = value;
		(*node)->balance = 0;
		(*node)->left = nullptr;
		(*node)->right = nullptr;

		return 1;
	}

	if ((*node)->value > value)
	{
		// Recursividade à esquerda
		ok = insere(&((*node)->left), value);

		if (ok)
		{
			// Próxima raiz a se verificar o FB
			switch ((*node)->balance)
			{
			case 1:		(*node)->balance = ok = 0; break;
			case 0:		(*node)->balance = -1;		break;
			case -1:	caso1(node); ok = 0; 	// FB(p) = -2
			}
		}
	}
	else if ((*node)->value < value)
	{
		// Recursividade à direita
		ok = insere(&((*node)->right), value);
		
		if (ok)
		{
			switch ((*node)->balance) {
			// Próxima raiz a se verificar o FB
			case -1:	(*node)->balance = ok = 0;	break;
			case 0:		(*node)->balance = 1;		break;
			case 1:		caso2(&(*node)); ok = 0; // FB(p) = 2 // Não propaga mais
			}
		}
	}
	else ok = 0;
	
	return ok;
}

// Rotina auxiliar de insere
// Item foi inserido à esquerda de T e causa
// desbalanceamento FB(T) = -2
void leftUnbalancing(Node* node)
{
	Node u = (*node)->left;

	if (u->balance == -1)
		rotateRight(&(*node)); // Sinais iguais e negativo
	else
		rot_esq_dir(&(*node)); // Sinais diferentes
	(*node)->balance = 0;
}

//Rotina auxiliar de insere
//Item foi inserido à direita de T e causa
//desbalanceamento FB(T) = 2
void caso2 (tAvl *node) {
tAvl u;
u = (*node )->dir;
if (u->bal == 1)
rot_esq(&(*node)); // sinais iguais e positivo
else
rot_dir_esq (&(*node)); // sinais diferentes
(*node ) → bal = 0;
}

//Rotina responsável pela rotação para a direita
void rotateRight(Node* node)
{
	Node u;

	u = (*node)->left;
	(*node)->left = u->right;
	
	u->right = *node;
	(*node)->balance = 0;
	
	*node = u;
}

//Rotina responsável pela rotação para a esquerda
void rot_esq (tAvl *node) {
tAvl u;
u = (*node )->dir;
(*node )->dir = u->esq;
u->esq = *node;
(*node ) → bal = 0;
*node = u;
}

//Rotina que rotaciona à esquerda e depois à direita
void rot_esq_dir (tAvl *node) {
tAvl u,v;
u = (*node )->esq;
v = u->dir;
u->dir = v->esq;
v->esq = u;
(*node )->esq = v->dir;
v->dir = *node;
if (v->bal == -1)
(*node )->bal = 1;
else
(*node )->bal = 0;
if (v->bal == 1)
u->bal = -1;
else u->bal = 0;
*node = v;
}

//Rotina que rotaciona a direita e depois a esquerda
void rot_dir_esq (tAvl *node) {
tAvl u,v;
u = (*node )->dir;
v = u->esq;
u->esq = v->dir;
v->dir = u;
(*node )->dir = v->esq;
v->esq = *node;
if (v->bal == 1)
(*node )->bal = -1;
else (*node )->bal = 0;
if (v->bal == -1)
u->bal = 1;
else u->bal = 0;
*node = v;
}