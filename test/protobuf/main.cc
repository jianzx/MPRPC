#include "test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug;

int main(){
    // LoginResponse rsp;
    // ResultCode *rc=rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("登录处理失败了");
    GetFriendListResponse rsp;
    ResultCode *rc=rsp.mutable_result();  //通过mutable获取成员对象的指针，因为为resultcode也生成了一个类
    rc->set_errcode(0);  //这个类里面也封装了相应的方法
    User *user1=rsp.add_friend_list();//对于普通变量，它是set_，对于列表，他知道你想增加一个是用add_，并且返回增加的对象的地址
    user1->set_name("zhang san");
    user1->set_age(18);
    user1->set_sex(User::MAN);

    User *user2=rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(20);
    user2->set_sex(User::MAN);

    std::cout<<rsp.friend_list_size()<<std::endl;  //通过_size可以返回列表中的个数
    return 0;
}



int main1(){
    //封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");
    std::string send_str;

    //对象数据序列化
    if(req.SerializeToString(&send_str)){
        std::cout<<send_str<<std::endl;
    }

    //从send_str反序列化一个login请求对象
    LoginRequest reqB;
    if(reqB.ParseFromString(send_str)){
        std::cout<<reqB.name()<<std::endl;
        std::cout<<reqB.pwd()<<std::endl;
    }
    return 0;
}
