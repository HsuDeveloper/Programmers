#include <iostream>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0, i = 0;
    //A�� ������ ȭ��
    string temp(name.length(), 'A');
    while (true) {
        //�ٲٰ� �ִ� ȭ�鿡 �ݿ��ϰ�
        temp[i] = name[i];
        //���߿� �����ɷ� ����� �߰��ϱ�
        name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';
        //�ٲ��� ���ڿ��� �����ϴٸ� ��� ����
        if (temp == name)    break;
        //�������� ���� ���������� ���� ����ϱ� 
        for (int move = 1; move < name.length(); move++) {
            //������ �̵��� �����ٸ� ���������� �̵��ϰ� �̵�Ƚ�� �ݿ�
            if (name[(i + move) % name.length()] != temp[(i + move) % name.length()]) {
                i = (i + move) % name.length();
                answer += move;
                break;
            }
            //�������� �̵��� �����ٸ� �������� �̵��ϰ� �̵�Ƚ�� �ݿ�
            else if (name[(i + name.length() - move) % name.length()] 
                != temp[(i + name.length() - move) % name.length()]) {
                i = (i + name.length() - move) % name.length();
                answer += move;
                break;
            }
        }
    }
    return answer;
}

int main(){
    string name = "JEROAAAAAAAEN";
    cout<<solution(name);
}