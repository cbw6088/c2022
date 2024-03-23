import  { useState } from 'react';
import styled from 'styled-components';
import { postArticlesApi } from '../api/Articles';
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../security/AuthContext';
import searchIcon from '../../assets/icon/click.png';

const Wrapper = styled.div`
    width: '100%';
    height: '100%';
`;
const TopVarContainer = styled.div`
    display: flex;
    //justify-content: space-between;
    align-items: center;
    width: 100%;
    height: 8vh;
    //padding: 0 30px;
    border-bottom: 1px solid #d4d3d3;
    /* box-shadow: 0 2px 4px rgba(0,0,0,0.1); */
`;
const InputContainer = styled.div`
    position: relative;
    width: 60%;
    display: flex;
    align-items: center;
    background-color: white;
    border: 1px solid #d4d3d3;
    border-radius: 20px;
    overflow: hidden;
    margin-left: 450px;
`;
const StyledSelect = styled.select`
  padding: 8px;
  border: none;
  background-color: white;
  color: #333;
  font-size: 12px;
  /* margin-right: 10px; */
`;
const QuestionInput = styled.input`
    flex-grow: 1;
    border: none;
    height: 30px;
    padding: 0 10px;
    border-radius: 20px 0 0 20px;
    &:focus {
        outline: none;
    }
`;
const QuestionButton = styled.button`
    background-image: url(${searchIcon});
    background-size: cover;
    position: absolute;
    background-repeat: no-repeat;
    background-position: center;
    background-color: transparent;
    border: none;
    width: 20px;
    height: 20px;
    right: 10px;
    cursor: pointer;

    &:focus {
        outline: none;
    }
`;
const LoginButton = styled.button`
    width: 10%;
    height: 40px; 
    margin-left: 400px;
    background-color: transparent;
    border: none;
    cursor: pointer;
    &:hover {
        //background-color: #0056b3;
        color: #4980ff;
    }
`;
const Component = styled.div`
    display: flex;
    flex-direction: column;
    margin-left: 25%;
    margin-top: 20px;
    //align-items: center;
    //justify-content: center;
`;
const TextStyle = styled.div`
    margin-bottom: 5px;
    margin-left: 5px;
    font-size: 14px;
    border: bold;
    color: #626262;
`;
const InputTitle = styled.input`
    width: 60%;
    padding: 10px;
    border: 1px solid #ddd;
    border-radius: 5px;
    margin-right: 10%;
    margin-bottom: 10px; 

    &:focus {
    outline: none;
    border-color: #e59a0e;
    }  
`;
const InputContent = styled.textarea`
    width: 60%;
    height: 300px;
    padding: 10px;
    border: 1px solid #ddd;
    border-radius: 5px;
    margin-bottom: 10px; 

    &:focus {
    outline: none;
    border-color: #e59a0e;
    }  
`;
const InputHashtag = styled.input`
    width: 60%;
    padding:  10px;
    border: 1px solid #ddd;
    border-radius: 5px;
    margin-bottom: 10px; 

    &:focus {
    outline: none;
    border-color: #e59a0e;
    }  
`;
const ButtonContainer = styled.div`
    display: flex;
    align-items: center;
    justify-content: center;
    /* gap: 10px; */
`;
const WriteButton = styled.button`
    width: 8vw;
    height: 40px;
    margin-left: 26.5%;
    border-radius: 5px;
    background-color: #007bff;
    color: white;
    font-size: 12px;
    border: none;
    cursor: pointer;
    transition: background-color 0.3s;
    &:hover {
        background-color: #e59a0e;
    }
    @media (max-width: 768px) {
        width: 20%;
        margin-left: 19rem;
    }
`;
const CancelButton = styled.button`
    width: 8vw;
    height: 40px;
    border-radius: 5px;
    margin-left: 10px;
    background-color: white;
    color: #007bff;
    font-size: 12px;
    border: 1.5px solid #007bff;
    cursor: pointer;
    transition: background-color 0.3s;
    &:hover {
        background-color: #e59a0e;
    }
    @media (max-width: 768px) {
        width: 20%;
        margin-left: 19rem;
    }
`;

export default function ArticlesWritePage() {
    const [title, setTitle] = useState('');
    const [content, setContent] = useState('');
    const [hashtag, setHashtag] = useState('');
    const auth = useAuth();
    const navigate = useNavigate();
    const onClick = () =>{
        // alert("버튼이 클릭되었습니다!");
        console.log("백엔드에 POST 요청 보내기")
        const Article = {
            title: title,
            content: content,
            hashtag: hashtag,
            userId: auth.username,
        }
        const handleSubmit = async () => {
            try {
                const response = await postArticlesApi(Article);
        
                if (response.status === 200) {
                    window.alert('등록 완료!!');
                    navigate('/articles');
                    console.log('등록 완료');
                } else {
                    console.log('등록 실패');
                }
            } catch (error) {
                console.log('에러 발생:', error);
            }
        }
        handleSubmit()
    }

    return (
        <Wrapper>
            <TopVarContainer>
                <InputContainer>
                    <StyledSelect id="pet-select">
                        <option value="">선택</option>
                        <option value="TITLE">제목</option>
                        <option value="CONTENT">내용</option>
                        <option value="ID">아이디</option>
                        <option value="NICKNAME">닉네임</option>
                        <option value="HASHTAG">해시태그</option>
                    </StyledSelect>
                    <QuestionInput placeholder="검색..." />
                    <QuestionButton/>
                </InputContainer>
                <LoginButton>로그아웃</LoginButton>
            </TopVarContainer>
            <Component>
                <TextStyle>Title</TextStyle>
                <InputTitle value={title} onChange={(e) => setTitle(e.target.value)} placeholder="제목" />
                <TextStyle>Note</TextStyle>
                <InputContent value={content} onChange={(e) => setContent(e.target.value)} placeholder="내용" />
                <TextStyle>Hashtag</TextStyle>
                <InputHashtag value={hashtag} onChange={(e) => setHashtag(e.target.value)} placeholder="#" />
            </Component>
            <ButtonContainer>
                <WriteButton onClick={onClick}>Save</WriteButton>
                <CancelButton onClick={onClick}>Cancel</CancelButton>
            </ButtonContainer>
        </Wrapper>
    );
}