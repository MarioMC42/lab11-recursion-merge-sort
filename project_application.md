# Lab 11 - Project Application

## E1 - Original collection and borrowed pointers
`orders` is the array that stores the actual `OrderPreview` records. The `view` array stores pointers to selected records in `orders`; it does not contain copies or own the records. `logicalCount` tracks how many pointers in `view` are valid.

## E2 - Implemented view and test
The program uses these four records:

- `101`: Delivery, Pending, building A, priority 3
- `102`: Dine-in, In Progress, building B, priority 1
- `103`: Delivery, Pending, building C, priority 2
- `104`: Delivery, Completed, building D, priority 1

The filter selects `Delivery` orders with status `Pending` or `In Progress`. The expected and observed selected IDs are `101` and `103`. Order `102` is active but is excluded because it is `Dine-in`; order `104` is excluded because it is completed.

The program prints the original orders before and after creating the view. Their IDs, priorities, types, statuses, buildings, and sequence remain the same, confirming that building the pointer view did not modify or reorder the original records.

## E3 - Sorting criterion and next integration step
The intended report ordering is:

1. Building name alphabetically.
2. Higher priority first within each building.
3. Lower `orderId` first when building and priority are tied.

For example, the expected order for `101 (A, priority 5)`, `118 (A, priority 5)`, `204 (A, priority 2)`, `215 (B, priority 3)`, and `310 (B, priority 3)` is `101, 118, 204, 215, 310`. These are illustrative comparator examples, not the four records used in the filter test.

The current practice builds and displays the filtered view but does not sort it. The next integration step is to apply the three-rule comparator in the merge sort on the pointers in `view`, without changing `orders`.

## E4 - Lab evidence
Source file: `delivery_view_practice.cpp`

Test output: `delivery_view_output.txt`

The output shows the four original records before and after filtering and the selected IDs `101` and `103`. This practice demonstrates how a temporary pointer view can support a future report while leaving the source collection in its original order.
