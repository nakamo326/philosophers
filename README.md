# philosophers
The Dining Philosophers Problem implementation of C.

## Overview

One of the assignment of 42Tokyo.
This is C implementation of the dining philosophers problem.

## Usage

```
./philo number_of_philosophers time_to_die time_to_eat
time_to_sleep [number_of_times_each_philosopher_must_eat]
```

The simulation ends when all philosophers have finished the number of meals specified in "number_of_times_each_philosopher_must_eat".

## Features

[/philo](./philo) uses pthread and mutex.
[/philo_bonus](./philo_bonus) uses process and semaphore.

## Reference

https://en.wikipedia.org/wiki/Dining_philosophers_problem
