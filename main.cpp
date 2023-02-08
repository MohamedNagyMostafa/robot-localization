#include <cstdio>
#include <vector>
#include <string>

typedef std::vector<float> vector_c;
typedef std::string string_c;

// Sensor Faulty.
const static float pHit     = 0.6;
const static float pMiss    = 0.2;

// Movement Uncertainty
const static float BACK_PROB    = 0.1;
const static float FORW_PROB    = 0.1;
const static float HIT_PROB     = 0.8;

void initialProbability(__int8& gridNumber, vector_c& world);
void sense(vector_c& world, string_c worldColors[], string_c& sensorSense);
void move(vector_c& world, __int8 steps);
void display(vector_c& world, string_c worldColors[]);

int main() {
    __int8 gridNumber1D = 5;
    string_c worldColors[] = {"green", "red", "red", "green", "green"};
    vector_c world;

    world.reserve(gridNumber1D);

    initialProbability(gridNumber1D, world);


    std::string sensorMeasurement[] = {"red", "green"};
    __int8 motions[]               = {1, 1};

    for(int32_t i = 0; i < 2; i++)
    {
        printf("Robot senses is %s", sensorMeasurement[i].c_str());
        sense(world, worldColors, sensorMeasurement[i]);
        display(world, worldColors);
        move(world, motions[i]);
    }
    display(world, worldColors);

    return 0;
}


void initialProbability(__int8& gridNumber, vector_c& world)
{
    world.assign(gridNumber, 1.f/(float)gridNumber);
}

void sense(vector_c& world, string_c worldColors[], string_c& sensorSense)
{
    float sum = 0.f;

    for(int32_t i = 0; i < world.size(); i++)
    {
        world[i] *= (worldColors[i]  == sensorSense)? pHit : pMiss;
        sum += world[i];
    }

    for(float& p : world)
    {
        p /= sum;
    }
}

void move(vector_c& world, __int8 steps)
{
    __int8 worldSize = world.size();
    steps *= -1;
    if(steps == 0 || steps % worldSize == 0) return;

    vector_c worldCopy;
    worldCopy.reserve(worldSize);
    worldCopy = world;

    auto idx = (int32_t) ((steps) % (int) worldSize);
    if (steps < 0)
        idx += (int32_t) worldSize;

    for(int32_t i = 0; i < worldSize; i++)
    {
        world[i] = worldCopy[idx] * HIT_PROB
                +  worldCopy[(idx - 1) % worldSize] * BACK_PROB
                +  worldCopy[(idx + 1) % worldSize] * FORW_PROB;
        idx =(int32_t) ((idx + 1) % worldSize);
    }

}

void display(vector_c& world, string_c worldColor[])
{
    printf("\n==========================\n");
    for(int i = 0 ; i < world.size(); i++)
    {
        printf("| [%s]:(%.3f) | ", worldColor[i].c_str(), world[i]);
    }
    printf("\n==========================\n");

}
