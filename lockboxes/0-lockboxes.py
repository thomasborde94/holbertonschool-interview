#!/usr/bin/python3

def canUnlockAll(boxes):
    if not boxes:
        return False

    boxNumber = len(boxes)
    unlocked_boxes = [0]  # Contains unlocked boxes, initialized with box 0

    keys_to_check = boxes[0]  # Initialize with keys in the first box

    while keys_to_check:  # while there are keys to open boxes
        new_keys = []
        for key in keys_to_check:  # check for each key in the keys we have
            if key < boxNumber and key not in unlocked_boxes:  # check if
                # the key is valid and we did not already open the box
                unlocked_boxes.append(key)  # append the corresponding
                # box to the unlocked boxes
                new_keys.extend(boxes[key])  # adds the key to all the
                # keys we have
        keys_to_check = new_keys  # update the keys to check

    return len(unlocked_boxes) == boxNumber  # check if we opened as many
# boxes as there are boxes
