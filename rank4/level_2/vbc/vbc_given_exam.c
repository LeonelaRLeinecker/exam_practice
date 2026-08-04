#include <stdio.h>
#include <stdlib.h> //cambiar <malloc.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");//change file for input
}

int accept(char **s, char c)
{
    if (**s==c) // add == c
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}


//...
node *parse_number(char **s)
{
		node n;
		
		if (!**s)
		{
				unexpected(**s);
				return (NULL);
		}
		if (!isdigit(**s))
		{
				unexpected(**s);
				return (NULL);
		}
		n.type = VAL;
		n.val = **s - 48;
		n.l = NULL;
		n.r = NULL;
		(*s)++;
		return (new_node(n));
}
node *parse_factor(char **s)
{
		node *ret;
		if (!**s)
		{
				unexpected(**s);
				return (NULL);
		}
		if (isdigit(**s))
				return (parse_number(s));
		if (accept(s, '('))
		{
				ret = parse_expr(s);
				if (!ret)
						return (NULL);
				if (!expect(s, ')'))
				{
						destroy_tree(ret);
						return (NULL);
				}
				return (ret);
		}
		unexpected(**s);
		return (NULL);
}

node *parse_term(char **s)
{
		node *ret = parse_factor(s);
		node *rigth;

		while (ret && accept(s, '*'))
		{
				if (!rigth = parse_term(s))
				{
						destroy_tree(ret);
						return (NULL);
				}
				if (!(ret = new_node((node){.type = MULTI, .l = ret, .r=rigth})))
				{
						destroy_tree(rigth);
						return (NULL);
				}
		}
		return (ret);
}

node    *parse_expr(char *s)
{
    node *ret = parse_factor(&s);
	if (!ret && !*s) 
    {
			unexpected(*s);
			destroy_tree(ret);
	        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}
