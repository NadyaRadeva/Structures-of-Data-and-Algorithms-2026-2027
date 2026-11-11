class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentLine;
        stack<int> sandwichStack;

        for(int i = 0; i < students.size(); ++i) {
            studentLine.push(students[i]);
        }

        for(int i = sandwiches.size() - 1; i >= 0; --i) {
            sandwichStack.push(sandwiches[i]);
        }

        int rotations = 0;

        while(!studentLine.empty() && !sandwichStack.empty()) {
            int currentStudent = studentLine.front();
            int currentSandwich = sandwichStack.top();

            if(currentStudent == currentSandwich) {
                studentLine.pop();
                sandwichStack.pop();
                rotations = 0;
            }
            else {
                studentLine.push(currentStudent);
                studentLine.pop();
                rotations++;
            }

            if(rotations == studentLine.size()) {
                break;
            }
        }

        return studentLine.size();
    }
};
