import supabase from '../supaDB';
import { Linking } from 'react-native';

export async function getUserByUsername(username) {
    let { data: user, error } = await supabase
      .from('users') // 'users'는 데이터베이스 테이블 이름입니다.
      .select('*')
      .eq('user_id', username) // 'user_id'는 테이블의 컬럼 이름입니다.
      .single();
  
    if (error) throw error;
    return user;
  }

export async function recordLogin(userId, loginMethod, ipAddress) {
  const loginRecord = {
    user_id: userId,
    // login_time: new Date().toISOString(),
    login_method: loginMethod,
    ip_address: ipAddress
  };
  console.log('Su');

  const { data, error } = await supabase
    .from('login_records')
    .insert([loginRecord]);

  if (error) {
    console.error('Error recording login:', error);
  }
}


export async function signInWithGithub() {
  try {
    // Supabase 클라이언트를 사용하여 OAuth 인증 시작
    // Github기준인데 실제로 git은 잘 안 쓰니까 바꿔도 상관은 없을거야. 참고한 자료가 git이라 테스트 삼아 해본거라
    const { data, error } = await supabase.auth.signInWithOAuth({
      provider: "github",
      options: {
        redirectTo: "http://localhost:19000", // 로그인 인증 후 돌아올 앱 주소
      },
    });
    if (error) {
      console.error('Login error:', error.message);
      return false;
    }
    // 로그인 처리 로직
    if (data?.url) {
      // 로그인 URL 처리
      await Linking.openURL(data.url);
      return true;
    } else {
      // 로그인 실패 처리
      return false;
    }
  } catch (error) {
    console.error('Exception error:', error?.message || error);
    return false;
  }
}
