#include <iostream>
#include <cmath>

double DegreeToRadian(double rad){
    const double PI = 3.14159265359;
    double result;

    result = (rad * PI) / 180;

    return result;
}

void TranslateVector(float arr[], float tArr[]){
    //Define Initial
    float vector[3][1] = {
            {arr[0]},
            {arr[1]},
            {arr[2]}
    };
    //Define Translation
    float translateMatrix[3][1] = {
            {tArr[0]},
            {tArr[1]},
            {tArr[2]}
    };
    //Translate
    float translatedVector[3][1] = {
            {vector[0][0] + translateMatrix[0][0]},
            {vector[1][0] + translateMatrix[1][0]},
            {vector[2][0] + translateMatrix[2][0]}

    };

    //Print Out Results
    std::cout << "Initial Vector:    "  << "Output Vector: " <<  std::endl;
    std::cout << vector[0][0] << "                   " << round(translatedVector[0][0]) << std::endl;
    std::cout << vector[1][0] << "     --------->    " << round(translatedVector[1][0]) << std::endl;
    std::cout << vector[2][0] << "                   " << round(translatedVector[2][0]) << std::endl;




}

void ScaleVector(float arr[], float sArr[]){
    //Define Initial
    float vector[3][1] = {
            {arr[0]},
            {arr[1]},
            {arr[2]}
    };
    //Define scale
    float scaleMatrix[3][1] = {
            {sArr[0]},
            {sArr[1]},
            {sArr[2]}
    };
    //Scale
    float scaledVector[3][1] = {
            {vector[0][0] * scaleMatrix[0][0]},
            {vector[1][0] * scaleMatrix[1][0]},
            {vector[2][0] * scaleMatrix[2][0]}

    };

    //Print Out Results
    std::cout << "Initial Vector:    "  << "Output Vector: " <<  std::endl;
    std::cout << vector[0][0] << "                   " << round(scaledVector[0][0]) << std::endl;
    std::cout << vector[1][0] << "     --------->    " << round(scaledVector[1][0]) << std::endl;
    std::cout << vector[2][0] << "                   " << round(scaledVector[2][0]) << std::endl;




}

void RotateVector(float arr[], double alphaX, double betaY, double thetaZ){
    //Define initial Vector
    float vector[3][1] = {
            {arr[0]},
            {arr[1]},
            {arr[2]}
    };
    //Define rotation matrix and angle inputs

    double rotationMatrix[3][3] = {
            {cos(betaY) * cos(alphaX), (sin(thetaZ) * sin(betaY) * cos(alphaX)) - (cos(thetaZ) * sin(alphaX)), (cos(thetaZ) * sin(betaY) * cos(alphaX)) + (sin(thetaZ) *
                                                                                                                                                           sin(alphaX))},

            {cos(betaY) * sin(alphaX), (sin(thetaZ) * sin(betaY) * sin(alphaX)) + (cos(thetaZ) * cos(alphaX)), (cos(thetaZ) * sin(betaY) * sin(alphaX)) - (sin(thetaZ) *
                                                                                                                                                           cos(alphaX))},

            {-sin(betaY), sin(thetaZ) * cos(betaY), cos(thetaZ) * cos(betaY)}

    };

    //Rotate
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




int main() {
    float vecX;
    float vecY;
    float vecZ;
    float inputVec[3];
    char decision;
    double alpha, beta, theta;
    float translateX, translateY, translateZ;
    float scaleX, scaleY, scaleZ;

    std::cout << "Input initial vector in order of x , y , then z: " << std::endl;
    std::cin >> vecX;
    std::cin >> vecY;
    std::cin >> vecZ;

    inputVec[0] = vecX;
    inputVec[1] = vecY;
    inputVec[2] = vecZ;


    std::cout << "Would you like to rotate, scale, or translate the vector? (R, S, T)" << std::endl;
    std::cin >> decision;
    if(decision == 82){
        std::cout << "Input rotation on each axis (x, y ,z) ; Input zero for no rotation" << std::endl;
        std::cin >> alpha;
        std::cin >> beta;
        std::cin >> theta;

        alpha = DegreeToRadian(alpha);
        beta = DegreeToRadian(beta);
        theta = DegreeToRadian(theta);

        RotateVector(inputVec, alpha, beta, theta);

    }
    else if(decision == 83){
        std::cout << "Input scale on each axis (x, y ,z) ; Input zero for no scale" << std::endl;
        std::cin >> scaleX;
        std::cin >> scaleY;
        std::cin >> scaleZ;

        float scaleArray[3] = {scaleX, scaleY, scaleZ};

        ScaleVector(inputVec, scaleArray);
    }
    else if(decision == 84){
        std::cout << "Input translation on each axis (x, y ,z) ; Input zero for no translation" << std::endl;
        std::cin >> translateX;
        std::cin >> translateY;
        std::cin >> translateZ;

        float translateArray[3] = {translateX,translateY,translateZ};


        TranslateVector(inputVec, translateArray);
    }
    else{
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}


