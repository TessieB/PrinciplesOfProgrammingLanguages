import sys
import string

#initializes variables with starting values
arg_length = len(sys.argv)
filename = ""
derivations = False
string_length = 3
dictionary = {} 
derivative = ""
left_NT_idx = 0
counter = 0
str_set = set()

#reads in command line argument and updates filename, string_length, and derivations values
for i in range(1,arg_length):
    if '-d' in sys.argv[i]:
        derivations = True
    elif '-l' in sys.argv[i]:
        string_length = int(str(sys.argv[i])[2:len(sys.argv[i])])
    else:
        filename = sys.argv[i]

#opens file and puts grammars in dictionary
for line in open(filename, "r"):
    temp = []
    line_to_add = ""
    line_items = line.strip().split(" ")
    derivative = line_items[1]
    for i in range(2, len(line_items)):
        if len(line_to_add) > 0:
            line_to_add = line_to_add + " " + line_items[i]
        else:
            line_to_add = line_to_add + line_items[i]
    if line_items[0] in dictionary:
        temp = dictionary[line_items[0]]
        temp.append(line_to_add)
        dictionary[line_items[0]] = temp
    else:
        dictionary[line_items[0]] = [line_to_add]

#creates a worklist with only the starting value and an empty list for the derivations
worklist = [[list(dictionary.keys())[0], []]]
print()

#creates a loop that continues until the worklist is empty and the whole derivation
#or string has been printed out
while(worklist):
    sentence = worklist.pop(0)
    sub = sentence[0].split()
    sub_length = len(sub)
    #checks if the string popped off has a length larger than the string length passed in through sys.argv
    if sub_length > string_length:
        continue
    #checks if there is a nonterminal and if so, records the index of the leftmost nonterminal
    left_NT_idx_found = False
    for i in range(len(sub)):
        if sub[i] in dictionary.keys():
            left_NT_idx = i
            left_NT_idx_found = True
            break
    #prints out the string or derivation if there are no nonterminals in the string and the string length
    #is equal to string length passed in through sys.argv
    if not left_NT_idx_found and sub_length == string_length:
        if not derivations:
            if sentence[0] not in str_set:
                str_set.add(sentence[0])
                counter += 1
                print(sentence[0])
        else:
            deriv_string = ""
            for i in range(len(sentence[1])):
                if i == 0:
                    deriv_string = list(dictionary.keys())[0] + " " + derivative + ' ' + sentence[1][i]
                else:
                    deriv_string = ' '*(len(list(dictionary.keys())[0])+1) + derivative +  ' ' + sentence[1][i]
                print(deriv_string)
            counter += 1
            print()
        continue
    #if there is a nonterminal, this loop switches that nonterminal with all its possible replacements
    #and then appends each one to the derivation list and appends that and the string to the worklist
    if left_NT_idx_found:
        for k in range(len(dictionary[sub[left_NT_idx]])):
            dict_value = dictionary[sub[left_NT_idx]][k]
            if left_NT_idx < len(sub)-1:
                temp = ' '.join(sub[0:left_NT_idx]) + ' ' + dict_value + ' ' + ' '.join(sub[left_NT_idx+1: len(sub)])
            else:
                temp = ' '.join(sub[0:left_NT_idx]) + ' ' + dict_value
            temp = temp.lstrip()
            derivation_list = sentence[1].copy()
            derivation_list.append(temp)
            worklist.append([temp, derivation_list])
if not derivations:
    print()
print('# of strings generated: ' + str(counter))
