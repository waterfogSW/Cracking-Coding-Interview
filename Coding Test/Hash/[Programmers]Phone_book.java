/* 프로그래머스 : 코딩테스트 연습 > 해시 > 전화번호 목록 */
/* 해시를 통해 중복연산을 최소화 하는 문제이나 Array.sort()의 오름차순 정렬 특성을 이용하여 풀어내었다.*/
import java.util.*;
public class Phone_book {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        for (int i = 0; i < phone_book.length; i++) {
            for (int j = i + 1; j < phone_book.length; j++) {
                if(phone_book[j].startsWith(phone_book[i])) return false;
            }
        }
        return true;
    }
}