using UnityEngine;
using UnityEngine.UI;
using System;
using System.Collections;
using System.Collections.Generic;

public class CreateTree : MonoBehaviour
{
    private Lpy.LpyUnity _lpyUnity;
    private List<GameObject> _tree;

    public List<string> lstring;
    public int LstringIndex = 0;

    public List<Material> materials;
    public List<GameObject> surfaces;

    private IEnumerator StartGenerateTree()
    {
        int index = 0;
        while (index < this._tree.Count)
        {
            this._tree[index].SetActive(true);
            index++;
            yield return new WaitForSeconds(.05f);
        }
        yield return null;
    }

    private void GenerateTree()
    {
        foreach (Transform child in transform)
            Destroy(child.gameObject);

        try
        {
            this._tree = this._lpyUnity.Interpret(lstring[LstringIndex]);
        }
        catch (Exception e)
        {
            Debug.LogWarning(e.ToString());
        }
    }

    private void Start()
    {
        StopAllCoroutines();

        GameObject.Find("LstringIndex").GetComponent<Text>().text = this.LstringIndex.ToString();
        this._lpyUnity = new Lpy.LpyUnity(gameObject, materials, surfaces);
        GenerateTree();

        StartCoroutine(StartGenerateTree());
    }
    private void OnApplicationQuit()
    {
        this._lpyUnity = null;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey("escape"))
            Application.Quit();
    }

    public void PlayCurrentTree()
    {
        StopAllCoroutines();

        foreach (var t in this._tree)
            t.SetActive(false);

        StartCoroutine(StartGenerateTree());
    }

    public void ReGenerateLstring()
    {
        StopAllCoroutines();

        GenerateTree();

        StartCoroutine(StartGenerateTree());
    }

    public void NextLstring()
    {
        StopAllCoroutines();

        this.LstringIndex = (this.LstringIndex + 1) % this.lstring.Count;
        GameObject.Find("LstringIndex").GetComponent<Text>().text = this.LstringIndex.ToString();
        GenerateTree();

        StartCoroutine(StartGenerateTree());
    }
    
    public void PrevLstring()
    {
        StopAllCoroutines();

        this.LstringIndex = (this.LstringIndex == 0) ? this.lstring.Count - 1 : this.LstringIndex - 1;
        GameObject.Find("LstringIndex").GetComponent<Text>().text = this.LstringIndex.ToString();
        GenerateTree();

        StartCoroutine(StartGenerateTree());
    }

    public void StartCustomLstring(Text lstring)
    {
        StopAllCoroutines();

        foreach (Transform child in transform)
            Destroy(child.gameObject);

        try
        {
            this._tree = this._lpyUnity.Interpret(lstring.text);
        }
        catch (Exception e)
        {
            Debug.LogWarning(e.ToString());
        }

        StartCoroutine(StartGenerateTree());
    }
}
