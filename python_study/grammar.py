
import os
import random

# 描述组织
class ssp:
    def __init__(self ,path ,s_time ,e_time ,literals):
        self.path = path
        self.s_time = s_time
        self.e_time = e_time
        self.literals = literals

class csv:
    def __init__(self,ideal_file,mode,s_time,e_time,literals):
        self.ideal_file = ideal_file
        self.mode = mode
        self.s_time = s_time
        self.e_time = e_time
        self.literals = literals
    

def split_string(input_string,delimiter):
    return input_string.split(delimiter)

def ssp_file_read(result, file,):
    if len(result) < 3:
        #print(f"Error: Not enough elements in result for file {file}")
        return None
    


    ssp_c = ssp(file, result[0], result[1], result[2])
    return ssp_c

def csv_file_read(result, file):
    if len(result) < 20:
        #print(f"Error: Not enough elements in result for file {file}")
        return None

    csv_c = csv(file, result[1], result[11], result[12], result[13])
    return csv_c

def file_read(file, results, ssp_read_results, csv_read_results):
    with open(file, 'r', encoding='utf-8') as f:
        for line in f:
            if results is ssp_read_results:
                split_result = split_string(line.strip(), '\t')
                ssp_c = ssp_file_read(split_result, file)
                if ssp_c:
                    results.append(ssp_c)
            else:
                split_result = split_string(line.strip(), ', ')
                csv_c = csv_file_read(split_result, file)
                if csv_c:
                    results.append(csv_c)

def comparison():
    return None  

def main():

    # 文件 -> 结构体数组  字典
    ssp_dict = {}

    #数据处理 -> 结构体数组
    ssp_read_results = []
    csv_read_results = []
    file_read('ssp.txt', ssp_read_results, ssp_read_results, csv_read_results)
    file_read('res.csv', csv_read_results, ssp_read_results, csv_read_results)

    '''
    for ssp_c in ssp_read_results:
        print(f"Path: {ssp_c.path}, Start Time: {ssp_c.s_time}, End Time: {ssp_c.e_time}, Literals: {ssp_c.literals}")

    for csv_c in csv_read_results:
        print(f"Ideal File: {csv_c.ideal_file}, Mode: {csv_c.mode}, Start Time: {csv_c.s_time}, End Time: {csv_c.e_time}, Literals: {csv_c.literals}")
    '''



if __name__ == "__main__":
    main()