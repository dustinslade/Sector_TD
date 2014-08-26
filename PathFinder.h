#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "World.h"
#include "WorldObj.h"

#include <queue>
#include <vector>
#include <list>
#include <cmath>

namespace PathFinder{ //using a namespace instead of a singleton, static object - why waste the memory?
    //to access a priority queue's underlying container, you must extend functionality
    template <class T, class S, class C>
        S& Container(std::priority_queue<T, S, C>& q) {
            struct HackedQueue : private std::priority_queue<T, S, C> {
                static S& Container(std::priority_queue<T, S, C>& q) {
                    return q.*&HackedQueue::c;
                }
            };
        return HackedQueue::Container(q);
    }
    //different enough from a "Grid" to be a new object
    typedef struct Node{
        int cost, posX, posY;
        Node* parent;
        Node(int cost = 0, int posX = 0, int posY = 0, Node* parent = 0) : cost(cost), posX(posX), posY(posY), parent(parent) {}
        //overloading operators will make the cpp file easier to read
        bool operator==(const Node& rhs){
            return (posX == rhs.posX && posY == rhs.posY);
        }
        bool operator<(const Node& rhs){
            return (posX == rhs.posX && posY == rhs.posY && cost < rhs.cost);
        }
    } Node;
    typedef struct NodeCompare{
        //compare n1 against a node n2
        bool operator()(const Node& n1, const Node& n2){
            //if n2 has a lower cost, it has a higher priority
            return n2.cost < n1.cost;
        }
    } NodeCompare;
    //a list is essentially a linked list, a vector is a robust array; if you do not need random access, lists are faster than vectors
    //we need random access for the priority queue, because it will constantly be resorted
    //also note that the open/closed searching method is less than optimal, we could be O(logn) but are O(n)
    //in reality, this should be rewritten with a map
    bool PathSearch(std::list<Node>& path, const World& World, const WorldObj& obj, const Node& target); //path is our output list
     /*
        Pre-condition: Want to more to next Node
        Post-condition: Next Node is
        Parameters: Node, vector, list of Node that are open or closed, current Node, World, Node's target
        Return Values: none
        */
    void NodeSuccessors(std::priority_queue<Node, std::vector<Node>, NodeCompare>& open, std::list<Node>& closed, Node* parentNode, const World& World, const Node& target);
     /*
        Pre-condition: Need a path strategy
        Post-condition: Given path
        Parameters: Current Position, and target
        Return Values: Path number
        */
    int Heuristic(int posX, int posY, const Node& target);
     /*
        Pre-condition: Want a new Node
        Post-condition: Free Parent Node selected
        Parameters: Vector of ParentNodes
        Return Values: none
        */
    void FreeparentNodes(std::vector<Node*> parentNodes);
}

#endif // PATHFINDER_H
