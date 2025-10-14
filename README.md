# Marine Traffic CSV Optimizer

## Overview

A high-performance C++ application designed to optimize marine traffic CSV files by filtering out non-ship entities and removing duplicate entries. Achieves **~30% file size reduction** while preserving essential maritime data.

### Key Features
- **Smart Filtering**: Removes non-ship objects from datasets
- **Duplicate Elimination**: Cleans redundant temporal entries
- **Performance Optimized**: Handles large datasets efficiently (100MB+)
- **Data Integrity**: Maintains all critical ship information

### Performance Metrics

| Input Size | Output Size | Reduction |
|------------|-------------|-----------|
| 137 MB     | 95.9 MB     | ~30%      |
| 500 MB     | 368.3 MB     | ~30%      |

## Installation & Compilation
### Method 1: Run .exe
Install the directory from github and run: `src/main.exe`
### Method 2: Build with GCC
If you want to make changes to the source code, then this option will be perfect for you. First install the directory from github. Then, in an open terminal, run the command to build the project from the src folder: `g++ main.cpp logic.cpp - o main.exe -I../include`

1. Install the directory from github
2. Go to `optimize-ships/src` at the terminal
3. Run build command: `g++ main.cpp logic.cpp - o main.exe -I../include`
4. Run `/main` or mannualy run `main.exe` from `optimize-ships/src`


## Prerequisites
### Marine Traffic Data Format (traffic.csv)
| Column | Type | Description |
|------------|-------------|-----------|
| id_track     | integer     | Unique track identifier     |
| id_marine     | integer     | Marine object identifier      |
| lat    | float     | Latitude coordinate      |
| lon     | float     | Longitude coordinate    |
| speed     | integer     | Vessel speed (knots)     |
| course     | integer     | Navigation course (degrees)    |
| age     | integer     | Data age (seconds)     |
| date_add     | string     | Timestamp of record     |
### Marine Object Format (ships.csv)
| Column | Type | Description |
|------------|-------------|-----------|
| id_marine | integer | Marine object identifier |
| identifier | string | Vessel identifier |
| mmsi | string | Maritime Mobile Service Identity |
| name | string | Vessel name |
| flag | string | Country flag |
| type | string | Vessel type classification |
| length | integer | Vessel length (meters) |
| port | string | Home port |
| col11-15 | various | Additional metadata |
## Additional
> [!IMPORTANT]
> The provided sample data is entirely artificially invented. Any resemblance to real maritime traffic patterns or vessel information is purely coincidental.