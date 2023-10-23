def solution(id_list, reports, k):
    id_dict = {}
    reported_ids = {}
    for id in id_list:
        id_dict[id] = []
        reported_ids[id] = 0
        
    for report in reports:
        user, reported = report.split()
        id_dict[user].append(reported)
    
    for id in id_list:
        id_dict[id] = list(set(id_dict[id]))
    
    for _, value in id_dict.items():
        for v in value:
            reported_ids[v] += 1
    
    report ,= False
    reported_id_list = []
    for id in id_list:
        if reported_ids[id] >= k:
            report = True
            reported_id_list.append(id)
            
    for id in id_list:
        id_dict[id] = list(set(id_dict[id]).intersection(set(reported_id_list)))
        reported_ids[id] = len(id_dict[id])
            
    if report:
        answer = [v for _,v in reported_ids.items()]
    else:
        answer = [0 for _ in range(len(id_list))]

    return answer