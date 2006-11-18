#define MAX_RELS 256
#define MAX_REL_NAME 256
#define INITIAL_RANDOM_SEED 0 // 0 means the number of seconds since 1.1.1970 will  be used
#define MAX_TRIES 20          // initial number of tries before starting over
#define MAX_TRIES_FACTOR 1    // rate of increase in MAX_TRIES for each iteration 
#define GRANULARITY 0
#define FLIP_FACTOR 3         
#define SHOW_PROGRESS 1
#define DESCRIBE_MODEL 1
//the following are currently unused
#define TEMPRATURE 10000.0        // > 0.0 < 10000000.0
#define COOLING_FACTOR 0.9996    // <= 1.0
