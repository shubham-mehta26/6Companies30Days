/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
// Author: wind2002

class LinkedList
{
public:
    int val;
    LinkedList *next;
    bool visited;
    LinkedList(int val)
    {
        this->val = val;
        this->next = NULL;
        this->visited = false;
    }
    void addNode(LinkedList *&head, int val)
    {
        LinkedList *temp = new LinkedList(val);
        if (!head)
        {
            head = temp;
            temp->next = head;
            return;
        }
        LinkedList *curr = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
        return;
    }
    void markNode(LinkedList *&curr, int k)
    {
        int i = 1;
        while (i < k)
        {
            curr = curr->next;
            if (!curr->visited)
                i++;
        }
        curr->visited = true;
        while (1)
        {
            curr = curr->next;
            if (!curr->visited)
                break;
        }
    }
};
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        LinkedList *head = NULL;
        LinkedList list(0);
        for (int i = 1; i <= n; i++)
            list.addNode(head, i);
        LinkedList *curr = head;
        for (int i = 0; i < n - 1; i++)
            list.markNode(curr, k);
        return curr->val;
    }
};
// @lc code=end
