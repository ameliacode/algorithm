def solution(today, terms, privacies):
    answer = []
    
    terms_dict = {}
    for t in terms:
        a, b = t.split()
        terms_dict[a] = int(b)
    
    now_year, now_month, now_day = map(int, today.split("."))
    
    for idx in range(len(privacies)):
        prev, t = privacies[idx].split()
        prev_year, prev_month, prev_day = map(int,prev.split("."))
        
        prev_day -= 1
        if prev_day == 0:
            prev_day = 28
            prev_month -= 1
        
        prev_month += terms_dict[t]
        if prev_month > 12:
            if prev_month % 12 == 0:
                prev_year += (prev_month // 12) - 1
                prev_month = 12
            else:
                prev_year += prev_month // 12
                prev_month %= 12

        if prev_year < now_year:
            answer.append(idx+1)
        elif prev_year == now_year:
            if prev_month < now_month:
                answer.append(idx+1) 
            elif prev_month == now_month:
                if prev_day < now_day:
                    answer.append(idx+1)
        
    return answer