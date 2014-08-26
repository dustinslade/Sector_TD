#include "PathFinder.h"

namespace PathFinder{
    bool PathSearch(std::list<Node>& path, const World& World, const WorldObj& obj, const Node& target){
        std::priority_queue<Node, std::vector<Node>, NodeCompare> open;
        std::list<Node> closed;
        std::vector<Node*> parentNodes;
        Node bestNode;
        //put our starting position into our queue of nodes to inspect
        Node start(Heuristic(obj.GetposX(), obj.GetposY(), target), obj.GetposX(), obj.GetposY());
        open.push(start);
        while(!open.empty()){
            bestNode = open.top(); //has the lowest score by definition
            open.pop();
            if(bestNode == target){ //made it to the target
                Node* ptrNode = &bestNode;
                while(ptrNode){ //this is where we would reconstruct the path
                    //also, because of the stack, we will not be able to use the parent pointers in path when we leave PathSearch
                    //we should only use the position members
                    path.push_front(*ptrNode); //we are getting the coordinates in reverse, so we must fill path in reverse order
                    ptrNode = ptrNode->parent;
                }
                FreeparentNodes(parentNodes); //prevents memory leaks
                return 1;
            }
            //if we don't use a ptr, our parent will not exist, because it is a local
            //each parent pointer would be to a deleted item in the stack
            //specific "bad" example: we pass-by-reference bestNode as the parent, then set the parent pointer to that bestNode,
            //when we leave NodeSuccessors, bestNode is assigned to a new Node,
            //this means that the previous parent pointer will now be the parent pointer for the new bestNode
            Node* parentNode = new Node(bestNode);
            parentNodes.push_back(parentNode);
            NodeSuccessors(open, closed, parentNode, World, target); //look at the Node's neighbors
            closed.push_back(bestNode);
        }
        FreeparentNodes(parentNodes); //prevents memory leaks
        return 0; //no path found
    }
    //check for towers and check for boundaries; if they exist, skip the creation of that node
    //pathfinding works for up, down, left, right, but not diagonal movement
    void NodeSuccessors(std::priority_queue<Node, std::vector<Node>, NodeCompare>& open, std::list<Node>& closed, Node* parentNode, const World& World, const Node& target){
        std::vector<Node>& openVec = Container(open);
        int offsetX, offsetY;
        bool skip;
        for(int i = 0; i < 4; ++i){
            offsetX = 0; offsetY = 0;
            skip = 0;
            if(i == 0) offsetY = -30; //up
            else if(i == 1) offsetY = 30; //down
            else if(i == 2) offsetX = -30; //left
            else if(i == 3) offsetX = 30; //right
            //check world boundary
            if(!(parentNode->posX + offsetX < 600 && parentNode->posY + offsetY < 600 && parentNode->posX + offsetX >= 0 && parentNode->posY + offsetY >= 0)) continue;
            //check for occupied spaces
            if(World.GetOccupiedSpace((parentNode->posX + offsetX)/30, (parentNode->posY + offsetY)/30).set) continue;
            Node newNode(parentNode->cost + Heuristic((parentNode->posX + offsetX), (parentNode->posY + offsetY), target), parentNode->posX + offsetX, parentNode->posY + offsetY, parentNode);
            //if the Node already exists on open or closed with a lower score, we can skip to the next neighbor
            //if the Node already exists on open or closed with a higher score, then we need to remove it
            //the erasing is somewhat expensive, but simplifies the implementation
            for(std::list<Node>::iterator itr = closed.begin(); itr != closed.end(); ++itr){
                if(*itr < newNode){
                    skip = 1;
                    break;
                }
                else if(*itr == newNode){
                    closed.erase(itr);
                    break;
                }
            }
            if(skip) continue;
            for(std::vector<Node>::iterator itr = openVec.begin(); itr != openVec.end(); ++itr){
                if(*itr < newNode){
                    skip = 1;
                    break;
                }
                else if(*itr == newNode){
                    openVec.erase(itr);
                    break;
                }
            }
            if(skip) continue;
            open.push(newNode);
        }
    }
    int Heuristic(int posX, int posY, const Node& target){
        return abs(posX - target.posX) + abs(posY - target.posY);
    }
    void FreeparentNodes(std::vector<Node*> parentNodes){
        for (unsigned int i = 0; i < parentNodes.size(); ++i) {
            delete parentNodes[i]; // Calls ~object and deallocates *tmp[i]
        }
        parentNodes.clear();
    }
}
