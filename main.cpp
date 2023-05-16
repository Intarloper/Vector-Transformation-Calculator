#include <iostream>
#include <cmath>

void InputVector(int arr[], int tArr[], double alphaX, double betaY, double thetaZ, char decision){
    //Define inital Vector
    int vector[3][1] = {
            {arr[0]},
            {arr[1]},
            {arr[2]}
    };
    //Define Transformation Matrix
    int transVector[3][3] = {
            {tArr[0], tArr[1], tArr[2]},
            {tArr[3], tArr[4], tArr[5]},
            {tArr[6], tArr[7] ,tArr[8]}
    };

    //Define rotation matrix and angle inputs

    double rotationMatrix[3][3] = {
            {cos(betaY) * cos(alphaX), (sin(thetaZ) * sin(betaY) * cos(alphaX)) - (cos(thetaZ) * sin(alphaX)), (cos(thetaZ) * sin(betaY) * cos(alphaX)) + (sin(thetaZ) *
                                                                                                                                                           sin(alphaX))},

            {cos(betaY) * sin(alphaX), (sin(thetaZ) * sin(betaY) * sin(alphaX)) + (cos(thetaZ) * cos(alphaX)), (cos(thetaZ) * sin(betaY) * sin(alphaX)) - (sin(thetaZ) *
                                                                                                                                                           cos(alphaX))},

            {-sin(betaY), sin(thetaZ) * cos(betaY), cos(thetaZ) * cos(betaY)}

    };

    if(decision == 82){
        double rotatedVector[3][1] = {
                {vector[0][0] * rotationMatrix[0][0] + vector[1][0] * rotationMatrix[0][1] + vector[2][0] * rotationMatrix[0][2]},
                {vector[0][0] * rotationMatrix[1][0] + vector[1][0] * rotationMatrix[1][1] + vector[2][0] * rotationMatrix[1][2]},
                {vector[0][0] * rotationMatrix[2][0] + vector[1][0] * rotationMatrix[2][1] + vector[2][0] * rotationMatrix[2][2]}
        };

        //Print out results
        std::cout << "Initial Vector:    "  << "Output Vector: " <<  std::endl;
        std::cout << vector[0][0] << "                   " << round(rotatedVector[0][0]) << std::endl;
        std::cout << vector[1][0] << "     --------->    " << round(rotatedVector[1][0]) << std::endl;
        std::cout << vector[2][0] << "                   " << round(rotatedVector[2][0]) << std::endl;
    }
    else if(decision == 84){
        //Define Output Vector
        int outVector[3][1] = {
                {vector[0][0] * transVector[0][0] + vector[1][0] * transVector[0][1] + vector[2][0] * transVector[0][2]},
                {vector[0][0] * transVector[1][0] + vector[1][0] * transVector[1][1] + vector[2][0] * transVector[1][2]},
                {vector[0][0] * transVector[2][0] + vector[1][0] * transVector[2][1] + vector[2][0] * transVector[2][2]}
        };



        //Print out results
        std::cout << "Initial Vector:    "  << "Output Vector: " <<  std::endl;
        std::cout << vector[0][0] << "                   " << outVector[0][0] << std::endl;
        std::cout << vector[1][0] << "     --------->    " << outVector[1][0] << std::endl;
        std::cout << vector[2][0] << "                   " << outVector[2][0] << std::endl;
    }
    else{
        std::cout << "Invalid" << std::endl;
    }

}

double DegreeToRadian(double rad){
    const double PI = 3.14159265359;
    double result;

    result = (rad * PI) / 180;

    return result;
}


int main() {
    int vecX;
    int vecY;
    int vecZ;
    int inputVec[3];
    char decision;

    double alpha, beta, theta;

    std::cout << "Input initial vector in order of x , y , then z: " << std::endl;
    std::cin >> vecX;
    std::cin >> vecY;
    std::cin >> vecZ;

    inputVec[0] = vecX;
    inputVec[1] = vecY;
    inputVec[2] = vecZ;


    std::cout << "Would you like to rotate or translate vector? (R or T)" << std::endl;
    std::cin >> decision;
    if(decision == 82){
        std::cout << "Input rotation on each axis (x, y ,z) ; Input zero for no rotation" << std::endl;
        std::cin >> alpha;
        std::cin >> beta;
        std::cin >> theta;

        alpha = DegreeToRadian(alpha);
        beta = DegreeToRadian(beta);
        theta = DegreeToRadian(theta);

        std::cout << alpha << std::endl;
    }
    else if(decision == 84){

    }
    else{
        std::cout << "Invalid" << std::endl;
    }

    int transformMatrix[] = {1, 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};



    InputVector(inputVec, transformMatrix, alpha, beta, theta, decision);

    return 0;
}


