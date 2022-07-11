/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Test;
struct Coordinates {
    int row;
    int col;
};

struct GarryNode {
    GarryNode *parent = nullptr;
    GarryNode *root = nullptr;
    vector<GarryNode *> children;

    int length = 0;
    int district = 0;
    int votesCounter = 0;
    bool districtTail;
    vector<vector<int>> region;
    Coordinates coordinates;
};

class GarrySolver {
public:
    GarrySolver() : map(5, vector<int>(5)),
                    solvedRegion(5, vector<int>(5)) {}

    string solve(const std::string &strMap) {
        map = strToGrid(strMap);
        createRootNode({0, 0});
        if (solved) return gridToStr(solvedRegion);
        return "";
    }

    friend Test;

private:
    unsigned int nodeCounter = 0;
    bool solved{false};
    vector<vector<int>> map;
    vector<vector<int>> solvedRegion;
    GarryNode *rootNode{nullptr};

    vector<vector<int>> strToGrid(const string &mat) {
        vector<vector<int>> out;
        auto rowVec = [](const string subStr) -> vector<int> {
            assert(subStr.size() == 5);
            vector<int> tmp(5);
            for (int i = 0; i < 5; ++i) {
                tmp[i] = (subStr[i] == 'O') ? 1 : 0;
            }
            return tmp;
        };

        int cursor = 0;
        int prev = 0;
        while ((cursor = (int)mat.find("\n", prev)) != (int)string::npos) {
            out.push_back(rowVec(mat.substr(prev, cursor - prev)));
            prev = cursor + 1;
        }
        if (prev < (int)mat.size()) out.push_back(rowVec(mat.substr(prev)));
        return out;
    }

    string gridToStr(const vector<vector<int>> region) {
        string out;
        for (int row = 0; row < 5; ++row) {
            if (row > 0) out += "\n";
            for (int col = 0; col < 5; ++col) {
                out += std::to_string(region[row][col]);
            }
        }
        return out;
    }

    // bool isCellValid(const Coordinates &c, const vector<vector<int>> &region) {
    bool isCellValid(const Coordinates &c, const vector<vector<int>> &region) {
        // if (c.row < 0 || c.row >= 5 || c.col < 0 || c.col >= 5) return false;
        if (c.row < 0 || c.row >= (int)region.size() || c.col < 0 || c.col >= (int)region.size()) return false;
        return true;
    };

    bool isCellEmptyAndAdjacentToDistrict(const Coordinates &c, const vector<vector<int>> &region, int district) {
        if (!isCellValidAndEmpty(c, region)) return false;
        if ((isCellValid({c.row, c.col - 1}, region) && region[c.row][c.col - 1] == district) ||
            (isCellValid({c.row - 1, c.col}, region) && region[c.row - 1][c.col] == district) ||
            (isCellValid({c.row, c.col + 1}, region) && region[c.row][c.col + 1] == district) ||
            (isCellValid({c.row + 1, c.col}, region) && region[c.row + 1][c.col] == district)) return true;
        return false;
    }

    bool isCellValidAndEmpty(const Coordinates &c, const vector<vector<int>> &region) {
        // if (c.row < 0 || c.row >= 5 || c.col < 0 || c.col >= 5) return false;
        if (c.row < 0 || c.row >= (int)region.size() || c.col < 0 || c.col >= (int)region.size()) return false;
        if (region[c.row][c.col] > 0) return false;
        return true;
    };

    void fillAdjacentCell(vector<vector<int>> &region, Coordinates c, int *adjacentCellCounter) {
        if (!isCellValidAndEmpty({c.row, c.col}, region)) return;
        region[c.row][c.col] = 8;
        *adjacentCellCounter += 1;
        fillAdjacentCell(region, {c.row, c.col - 1}, adjacentCellCounter);
        fillAdjacentCell(region, {c.row - 1, c.col}, adjacentCellCounter);
        fillAdjacentCell(region, {c.row, c.col + 1}, adjacentCellCounter);
        fillAdjacentCell(region, {c.row + 1, c.col}, adjacentCellCounter);
    }

    bool isDeadEnd(vector<vector<int>> region) {
        int adjacentCellCounter = 0;
        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 5; ++col) {
                if (region[row][col] == 0) {
                    adjacentCellCounter = 0;
                    fillAdjacentCell(region, {row, col}, &adjacentCellCounter);
                    if (adjacentCellCounter % 5 != 0) return true;
                }
            }
        }
        return false;
    }

    // bool isTwoInDistrict(GarryNode *tailNode) {
    //     int voters = 0;
    //     for(int row = 0; row<5; ++row) {
    //         for(int col = 0; col<5; ++col) {
    //             if(tailNode->region[row][col]==tailNode->district)
    //         }
    //     }
    // }

    bool isSolved(vector<vector<int>> &_map, vector<vector<int>> &region) {
        vector<int> districtsVec(5);

        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 5; ++col) {
                if (_map[row][col]) {
                    districtsVec[region[row][col] - 1] += 1;
                }
            }
        }

        int majorDistricts = 0;
        for (auto val : districtsVec)
            (val > 2) ? ++majorDistricts : true;
        return majorDistricts > 2;
    }

    void createRootNode(const Coordinates c) {
        assert(c.row >= 0 && c.row < 5 && c.col >= 0 && c.col < 5);
        nodeCounter = 1;
        GarryNode *root = new GarryNode;

        root->coordinates.row = c.row;
        root->coordinates.col = c.col;

        root->root = root;
        root->length = 1;
        root->district = 1;
        root->districtTail = false;

        if (map[root->coordinates.row][root->coordinates.col] == 1) {
            root->votesCounter = 1;
        } else {
            root->votesCounter = 0;
        }

        vector<vector<int>> tmp(5, vector<int>(5));
        root->region = tmp;
        root->region[c.row][c.col] = root->district;
        rootNode = root;
        createNodChildren(root);
    };

    GarryNode *createNode(GarryNode *parent, Coordinates c) {
        assert(c.row >= 0 && c.row < 5 && c.col >= 0 && c.col < 5);
        ++nodeCounter;
        GarryNode *node = new GarryNode;
        if (solved) return node;
        node->parent = parent;
        node->coordinates.row = c.row;
        node->coordinates.col = c.col;
        node->length = parent->length + 1;
        node->district = (node->length - 1) / 5 + 1;
        node->districtTail = ((node->length) % 5 == 0) ? true : false;
        node->region = parent->region;
        node->region[c.row][c.col] = node->district;
        if (node->parent->districtTail) {
            node->votesCounter = 0;
        } else {
            node->votesCounter = parent->votesCounter;
        }
        if (map[node->coordinates.row][node->coordinates.col] == 1) node->votesCounter += 1;

        if (node->length == 25) {
            if (isSolved(map, node->region)) {
                solved = true;
                solvedRegion = node->region;
            }
            return node;
        } else if (node->districtTail && node->votesCounter == 2) {
            return node;
        } else if (node->districtTail && isDeadEnd(node->region)) {
            return node;
        // } else if ((node->districtTail || true) &&
        } else if ((node->length == 2 || node->length == 4 || node->length == 9) ||
                   node->length == 14 || node->length == 19) {
            createNodChildrenAdjacentToDistrict(node, node->district);
        } else {
            createNodChildren(node);
        }
        return node;
    }

    void createNodChildren(GarryNode *node) {
        if (isCellValidAndEmpty({node->coordinates.row, node->coordinates.col - 1}, node->region))
            node->children.push_back(createNode(node, {node->coordinates.row, node->coordinates.col - 1}));
        if (isCellValidAndEmpty({node->coordinates.row - 1, node->coordinates.col}, node->region))
            node->children.push_back(createNode(node, {node->coordinates.row - 1, node->coordinates.col}));
        if (isCellValidAndEmpty({node->coordinates.row, node->coordinates.col + 1}, node->region))
            node->children.push_back(createNode(node, {node->coordinates.row, node->coordinates.col + 1}));
        if (isCellValidAndEmpty({node->coordinates.row + 1, node->coordinates.col}, node->region))
            node->children.push_back(createNode(node, {node->coordinates.row + 1, node->coordinates.col}));
    }

    void createNodChildrenAdjacentToDistrict(GarryNode *node, int district) {
        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 5; ++col) {
                if (isCellEmptyAndAdjacentToDistrict({row, col}, node->region, district))
                    node->children.push_back(createNode(node, {row, col}));
            }
        }
    }
};

std::string gerrymander(const std::string &map) {
    GarrySolver solver;
    string res = solver.solve(map);
    std::cerr << '\n' << map << " :\n" << res << "\n\n";
    if (res.empty()) return "";
    return res;
}

int main() {
    std::string a = "XXOXO\nXOXOX\nOXOXO\nXOXOX\nXXOXX";
    std::string b = "XXXXX\nOOOXO\nXXXOX\nOOOOO\nXXXXX";
    std::cout << gerrymander(a) << '\n';
    std::cout << gerrymander(b) << '\n';

    return 0;
}