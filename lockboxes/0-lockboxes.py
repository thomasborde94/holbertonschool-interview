#!/usr/bin/python3

def canUnlockAll(boxes):
    if not boxes:
        return False

    boxNumber = len(boxes)
    unlocked_boxes = [0]

    keys_to_check = boxes[0]  # Initialize with keys in the first box

    while keys_to_check:
        new_keys = []
        for key in keys_to_check:
            if key < boxNumber and key not in unlocked_boxes:
                unlocked_boxes.append(key)
                new_keys.extend(boxes[key])
        keys_to_check = new_keys

    return len(unlocked_boxes) == boxNumber
