using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Wrapper;

namespace EasyUOSandbox
{
 
    public class EasyUO
    {

        public string UODllInfo = "game.dll v" + DLLWrap.Version().ToString();

        private IntPtr _uoHandle = new IntPtr(); 

        public EasyUO()
        {
            _uoHandle = DLLWrap.Open();
        }


        #region CharList
        public ArrayList OnlineCharlist()
        {
            for (int i = 1; i <= CliCnt; i++)
            {
                CliNr = i;
                EventMacro(8, 2);
            }
            Thread.Sleep(1000);

            ArrayList _ret = new ArrayList();
            int OriginalNr = CliNr;
            for (int i = 1; i <= CliCnt; i++)
            {
                CliNr = i;
                EventMacro(8, 2);
                int _cID = CharID;
                string _char = CharName;
                if (string.IsNullOrEmpty(_char))
                {
                    _char = CharName;
                }
                if (!string.IsNullOrEmpty(_char))
                {
                    _ret.Add(CharName);
                }
            }
            CliNr = OriginalNr;
            return _ret;

        }
        #endregion

        #region []FceList Character Selection
        public int ClientIbyCharName(string cName)
        {
            int _ret = 0;
            int OriginalNr = CliNr;
            for (int i = 1; i <= CliCnt; i++)
            {
                CliNr = i;
                int _cID = CharID;
                string _char = CharName;
                if (string.IsNullOrEmpty(_char))
                {
                    EventMacro(8, 2);
                    _char = CharName;
                }
                if (!string.IsNullOrEmpty(_char))
                {
                    _ret = i;
                }
            }
            CliNr = OriginalNr;
            return _ret;

        }

        #endregion



        #region Open/Close [Open provadi konstruktor]
        public bool Open()
        {
            _uoHandle = DLLWrap.Open();
            var _v = DLLWrap.Version();
            if (_v != 3) { return false; }
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Set");
            DLLWrap.PushStrVal(_uoHandle, "CliNr");
            DLLWrap.PushInteger(_uoHandle, 1);
            if (DLLWrap.Execute(_uoHandle) != 0)
            {
                return false;
            };
            return true;
        }

        public void Close()
        {
            DLLWrap.Close(_uoHandle);
        }

        #endregion

        #region Character Info
        public ushort CharPosX
        {
            get
            {
                return (ushort)GetInt("CharPosX");
            }
        }
        public ushort CharPosY
        {
            get
            {
                return (ushort)GetInt("CharPosY");
            }
        }
        public byte CharPosZ
        {
            get
            {
                return (byte)GetInt("CharPosZ");
            }
        }
        public int CharDir
        {
            get
            {
                return GetInt("CharDir");
            }
        }
        public int CharID
        {
            get
            {
                return GetInt("CharID");
            }
        }
        public int CharType
        {
            get
            {
                return GetInt("CharType");
            }
        }
        public int CharStatus
        {
            get
            {
                return GetInt("CharStatus");
            }
        }
        public int BackpackID
        {
            get
            {
                return GetInt("BackpackID");
            }
        }
        #endregion
        #region Status Info
        public string CharName
        {
            get
            {
                return GetString("CharName");
            }
        }

        public int Sex
        {
            get
            {
                return GetInt("Sex");
            }
        }

        public int Str
        {
            get
            {
                return GetInt("Str");
            }
        }

        public int Dex
        {
            get
            {
                return GetInt("Dex");
            }
        }

        public int Int
        {
            get
            {
                return GetInt("Int");
            }
        }

        public int Hits
        {
            get
            {
                return GetInt("Hits");
            }
        }

        public int MaxHits
        {
            get
            {
                return GetInt("MaxHits");
            }
        }

        public int Stamina
        {
            get
            {
                return GetInt("Stamina");
            }
        }

        public int MaxStam
        {
            get
            {
                return GetInt("MaxStam");
            }
        }

        public int Mana
        {
            get
            {
                return GetInt("Mana");
            }
        }

        public int MaxMana
        {
            get
            {
                return GetInt("MaxMana");
            }
        }

        public int MaxStats
        {
            get
            {
                return GetInt("MaxStats");
            }
        }

        public int Luck
        {
            get
            {
                return GetInt("Luck");
            }
        }

        public int Weight
        {
            get
            {
                return GetInt("Weight");
            }
        }

        public int MaxWeight
        {
            get
            {
                return GetInt("MaxWeight");
            }
        }

        public int MinDmg
        {
            get
            {
                return GetInt("MinDmg");
            }
        }

        public int MaxDmg
        {
            get
            {
                return GetInt("MaxDmg");
            }
        }

        public int Gold
        {
            get
            {
                return GetInt("Gold");
            }
        }

        public int Followers
        {
            get
            {
                return GetInt("Followers");
            }
        }

        public int MaxFol
        {
            get
            {
                return GetInt("MaxFol");
            }
        }

        public int AR
        {
            get
            {
                return GetInt("AR");
            }
        }

        public int FR
        {
            get
            {
                return GetInt("FR");
            }
        }

        public int CR
        {
            get
            {
                return GetInt("CR");
            }
        }

        public int PR
        {
            get
            {
                return GetInt("PR");
            }
        }

        public int ER
        {
            get
            {
                return GetInt("ER");
            }
        }

        public int TP
        {
            get
            {
                return GetInt("TP");
            }
        }
        #endregion
        #region Client Info
        public int CliNr
        {
            get
            {
                return GetInt("CliNr");
            }
            set
            {
                SetInt("CliNr", value);
            }
        }
        public int CliCnt
        {
            get
            {
                return GetInt("CliCnt");
            }
        }
        public string CliLang
        {
            get
            {
                return GetString("CliLang");
            }
        }
        public int CliVer
        {
            get
            {
                return GetInt("CliVer");
            }
        }
        public bool CliLogged
        {
            get
            {
                return GetBoolean("LObjectID");
            }
        }
        public int CliLeft
        {
            get
            {
                return GetInt("CliLeft");
            }
        }
        public int CliTop
        {
            get
            {
                return GetInt("CliTop");
            }
        }
        public int CliXRes
        {
            get
            {
                return GetInt("CliXRes");
            }
        }
        public int CliYRes
        {
            get
            {
                return GetInt("CliYRes");
            }
        }
        public string CliTitle
        {
            get
            {
                return GetString("CliTitle");
            }
            set
            {
                SetString("CliTitle", value);
            }
        }
        #endregion
        #region Misc
        public int EnemyHits
        {
            get
            {
                return GetInt("EnemyHits");
            }
        }
        public int EnemyID
        {
            get
            {
                return GetInt("EnemyID");
            }
        }
        public int RHandID
        {
            get
            {
                return GetInt("RHandID");
            }
        }
        public int LHandID
        {
            get
            {
                return GetInt("LHandID");
            }
        }
        public int CursorX
        {
            get
            {
                return GetInt("CursorX");
            }
        }
        public int CursorY
        {
            get
            {
                return GetInt("CursorY");
            }
        }
        public int CursKind
        {
            get
            {
                return GetInt("CursKind");
            }
        }
        public bool TargCurs
        {
            get
            {
                return GetBoolean("TargCurs");
            }
            set
            {
                SetBoolean("TargCurs", value);
            }
        }
        public string Shard
        {
            get
            {
                return GetString("Shard");
            }
        }
        public string LShard
        {
            get
            {
                return GetString("LShard");
            }
        }
        public string SysMsg
        {
            get
            {
                return GetString("SysMsg");
            }
        }
        #endregion

        #region Last Action
        public int LObjectID
        {
            get
            {
                return GetInt("LObjectID");
            }
            set
            {
                SetInt("LObjectID", value);
            }
        }
        public int LObjectType
        {
            get
            {
                return GetInt("LObjectType");
            }
            set
            {
                SetInt("LObjectType", value);
            }
        }
        public int LTargetID
        {
            get
            {
                return GetInt("LTargetID");
            }
            set
            {
                SetInt("LTargetID", value);
            }
        }
        public int LTargetKind
        {
            get
            {
                return GetInt("LTargetKind");
            }
            set
            {
                SetInt("LTargetKind", value);
            }
        }
        public int LTargetTile
        {
            get
            {
                return GetInt("LTargetTile");
            }
            set
            {
                SetInt("LTargetTile", value);
            }
        }
        public int LTargetX
        {
            get
            {
                return GetInt("LTargetX");
            }
            set
            {
                SetInt("LTargetX", value);
            }
        }
        public int LTargetY
        {
            get
            {
                return GetInt("LTargetY");
            }
            set
            {
                SetInt("LTargetY", value);
            }
        }
        public int LTargetZ
        {
            get
            {
                return GetInt("LTargetZ");
            }
            set
            {
                SetInt("LTargetZ", value);
            }
        }
        public int LLiftedID
        {
            get
            {
                return GetInt("LLiftedID");
            }
            set
            {
                SetInt("LLiftedID", value);
            }
        }
        public int LLiftKind
        {
            get
            {
                return GetInt("LLiftKind");
            }
            set
            {
                SetInt("LLiftKind", value);
            }
        }
        public int LLiftType
        {
            get
            {
                return GetInt("LLiftType");
            }
            set
            {
                SetInt("LLiftType", value);
            }
        }
        public int LSkill
        {
            get
            {
                return GetInt("LSkill");
            }
            set
            {
                SetInt("LSkill", value);
            }
        }
        public int LSpell
        {
            get
            {
                return GetInt("LSpell");
            }
            set
            {
                SetInt("LSpell", value);
            }
        }
        #endregion

        #region Custom Helper Commands

        private int journalRef = 0;
        private List<string> journal = new List<string>();
        /// <summary>
        /// Finds the designated string in new journal entries since last call.
        /// </summary>
        /// <param name="StringToFind"></param>
        /// <returns>True if found, False if not found</returns>
        public bool InJournal(string StringToFind)
        {
            journal.Clear(); // Maybe dont clear?
            var jf = this.ScanJournal(journalRef);
            if (jf.NewRef > journalRef)
            { // new journal entries
                for (int i = journalRef; i < jf.NewRef; i++)
                {
                    journal.Add(GetJournal(i).Line);
                }
                journalRef = jf.NewRef;
            }

            if (journal.Where(j => j.ToLower().Contains(StringToFind.ToLower())).Count() > 0)
                return true;
            return false;
        }
        /// <summary>
        /// Finds the designated string in new journal entries since last call.
        /// </summary>
        /// <param name="StringsToFind"></param>
        /// <returns>Returns found string or string.Empty if not found</returns>
        public string InJournal(string[] StringsToFind)
        {
            journal.Clear(); // Maybe dont clear?
            var jf = this.ScanJournal(journalRef);
            if (jf.NewRef > journalRef)
            { // new journal entries
                for (int i = journalRef; i < jf.NewRef; i++)
                {
                    journal.Add(GetJournal(i).Line);
                }
                journalRef = jf.NewRef;
            }

            foreach (string s in StringsToFind)
            {
                if (journal.Where(j => j.ToLower().Contains(s.ToLower())).Count() > 0)
                    return s;
            }
            return string.Empty;
        }

        /// <summary>
        /// Sleeps for designated time in EasyUO style 10 = 500ms 20 = 1s
        /// </summary>
        /// <param name="Time"></param>
        public void Wait(int Time)
        {
            Thread.Sleep((Time * 100) / 2);
        }

        /// <summary>
        /// Waits the designated timeout for a Target cursor, or 2000ms
        /// </summary>
        /// <param name="TimeOutMS"></param>
        /// <returns>True if target cursor is active</returns>
        public bool Target(int TimeOutMS = 2000)
        {
            System.Diagnostics.Stopwatch _stopwatch = new System.Diagnostics.Stopwatch(); _stopwatch.Start();
            while (_stopwatch.ElapsedMilliseconds < TimeOutMS)
            {
                if (this.TargCurs)
                    return true;
                Thread.Sleep(10);
            }
            return false;
        }
        /// <summary>
        /// Returns list of FoundItem matching Type or ID
        /// </summary>
        /// <param name="TypeOrID"></param>
        /// <param name="VisibleOnly">Search for visible items only</param>
        /// <returns>Returns list of FoundItem matching Type or ID</returns>
        public List<FoundItem> FindItem(int TypeOrID, bool VisibleOnly = true)
        {
            int itemcnt = ScanItems(VisibleOnly);
            List<FoundItem> items = new List<FoundItem>();
            for (int i = 0; i < itemcnt; i++)
            {
                FoundItem item = GetItem(i);
                if (item != null)
                {
                    if (item.Type == TypeOrID || item.ID == TypeOrID || TypeOrID == 0)
                        items.Add(item);
                }

            }

            return items;
        }
        /// <summary>
        /// Returns list of FoundItem matching Type or ID
        /// </summary>
        /// <param name="TypeOrID"></param>
        /// <param name="VisibleOnly"> Search for visible items only</param>
        /// <returns>Returns list of FoundItem matching Type or ID</returns>
        public List<FoundItem> FindItem(ushort[] Types, bool VisibleOnly = true)
        {
            List<FoundItem> items = new List<FoundItem>();
            foreach (var ty in Types)
                items.AddRange(FindItem(ty, true));
            return items;
        }


        public void UseSkill(Enums.Skill Skill)
        {
            EventMacro(13, (int)Skill);
        }

        #endregion
        // ToDo SKilllock/Statlock
        #region Supported GameDLL Events
        /// <summary>
        /// This method of dragging should be used with a click to drop.
        /// </summary>
        /// <param name="ItemID"></param>
        public void CliDrag(int ItemID)
        {
            // This should be completed with a click to drop, use Drag.
            _executeCommand(false, "CliDrag", new object[] { ItemID });
        }

        public void Drag(int ItemID, int Amount)
        {
            _executeCommand(false, "Drag", new object[] { ItemID, Amount });
        }
        public void DropC(int ContID, int X, int Y)
        {
            _executeCommand(false, "DropC", new object[] { ContID, X, Y });
        }
        public void DropC(int ContID)
        {
            _executeCommand(false, "DropC", new object[] { ContID });
        }

        public void DropG(int X, int Y, int Z)
        {
            _executeCommand(false, "DropG", new object[] { X, Y, Z });
        }
        public void ExMsg(int ItemID, int FontID, int Color, string Message)
        {
            _executeCommand(false, "ExMsg", new object[] { ItemID, FontID, Color, Message });
        }


        public void PathFind(int X, int Y, int Z)
        {
            _executeCommand(false, "PathFind", new object[] { X, Y, Z });
        }
        public PropertyInfo Property(int ItemID)
        {
            PropertyInfo p = new PropertyInfo();
            var o = _executeCommand(true, "Property", new object[] { ItemID });
            if (o == null) { return null; } // Maybe return empty prop instead
            p.Name = (string)o[0];
            p.Info = (string)o[1];
            return p;
        }
        public void RenamePet(int ID, string Name)
        {
            _executeCommand(false, "RenamePet", new object[] { ID, Name });
        }

        #endregion

        #region Supported GameDLL Commands
        public void Click(int X, int Y, bool Left, bool Down, bool Up, bool Middle)
        {
            _executeCommand(false, "Click", new object[] { X, Y, Left, Down, Up, Middle });
            /*DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Call");
            DLLWrap.PushStrVal(_uoHandle, "Click");
            DLLWrap.PushInteger(_uoHandle, X);
            DLLWrap.PushInteger(_uoHandle, Y);
            DLLWrap.PushBoolean(_uoHandle, Left);
            DLLWrap.PushBoolean(_uoHandle, Down);
            DLLWrap.PushBoolean(_uoHandle, Up);
            DLLWrap.PushBoolean(_uoHandle, Middle);
            var result = DLLWrap.Execute(_uoHandle);
            return;*/
        }


        public FoundItem GetItem(int index)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Call");
            DLLWrap.PushStrVal(_uoHandle, "GetItem");
            DLLWrap.PushInteger(_uoHandle, index);
            if (DLLWrap.Execute(_uoHandle) != 0)
                return null;
            FoundItem item = new FoundItem();
            item.ID = DLLWrap.GetInteger(_uoHandle, 1);
            item.Type = DLLWrap.GetInteger(_uoHandle, 2);
            item.Kind = DLLWrap.GetInteger(_uoHandle, 3);
            item.ContID = DLLWrap.GetInteger(_uoHandle, 4);
            item.X = DLLWrap.GetInteger(_uoHandle, 5);
            item.Y = DLLWrap.GetInteger(_uoHandle, 6);
            item.Z = DLLWrap.GetInteger(_uoHandle, 7);
            item.Stack = DLLWrap.GetInteger(_uoHandle, 8);
            item.Rep = DLLWrap.GetInteger(_uoHandle, 9);
            item.Col = DLLWrap.GetInteger(_uoHandle, 10);
            return item;

        }
        public JournalEntry GetJournal(int index)
        {
            var results = _executeCommand(true, "GetJournal", new object[] { index });
            if (results != null)
                return new JournalEntry((string)results[0], (int)results[1]);
            return null;
        }
        public int GetPix(int X, int Y)
        {
            var results = _executeCommand(true, "GetPix", new object[] { X, Y });
            if (results != null) { return (int)results[0]; }
            return 0;
        }
        public Skill GetSkill(string SKill)
        {
            //Todo Replace with enum?
            return null;
        }
        public void HideItem(int ID)
        {
            _executeCommand(false, "HideItem", new object[] { ID });
        }
        public void Key(string Key, bool Ctrl, bool Alt, bool Shift)
        {
            _executeCommand(false, "Key", new object[] { Key, Ctrl, Alt, Shift });
        }
        public bool Move(int X, int Y, int Accuracy, int TimeoutMS)
        {
            var results = _executeCommand(true, "Move", new object[] { X, Y, Accuracy, TimeoutMS });
            if (results != null) { if ((string)results[0] == "true") { return true; } return false; }
            return false;
        }
        public void Msg(string Message)
        {
            _executeCommand(false, "Msg", new object[] { Message });
        }

        public int ScanItems(bool VisibleOnly)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Call");
            DLLWrap.PushStrVal(_uoHandle, "ScanItems");
            DLLWrap.PushBoolean(_uoHandle, VisibleOnly);
            if (DLLWrap.Execute(_uoHandle) != 0)
                return 0;
            return DLLWrap.GetInteger(_uoHandle, 1);
        }
        public JournalScan ScanJournal(int OldRef)
        {
            var results = _executeCommand(true, "ScanJournal", new object[] { OldRef });
            if (results != null)
            {
                JournalScan j = new JournalScan();
                j.NewRef = (int)results[0];
                j.Cnt = (int)results[1];
                return j;
            }
            return null;
        }

        public Container GetCont(int Index)
        {
            var results = _executeCommand(true, "GetCont", new object[] { Index });
            if (results == null) { return null; }
            return new Container(results);

        }
        public void ContTop(int Index)
        {
            _executeCommand(false, "ContTop", new object[] { Index });
        }

        //Probably should replace tile commands with openuo rather than uo.dll
        public bool TileInit(bool NoOverRides)
        {
            var results = _executeCommand(true, "TileInit", new object[] { NoOverRides });
            if (results != null) { return (bool)results[0]; }
            return false;
        }
        public int TileCnt(int X, int Y, int Facet)
        {
            var results = _executeCommand(true, "TileCnt", new object[] { X, Y, Facet });
            if (results != null) { return (int)results[0]; }
            return 0;
        }
        public Tile TileGet(int X, int Y, int Index, int Facet)
        {
            var results = _executeCommand(true, "TileGet", new object[] { X, Y, Index, Facet });
            if (results != null) { return new Tile(results); }
            return null;
        }
        #endregion

        #region DataTypes
        public class Tile
        {
            public int Type, Z;
            public string Name;
            public int Flags;
            public Tile(List<object> data)
            {
                if (data.Count() < 4)// throw an error
                    return;
                this.Type = (int)data[0];
                this.Z = (int)data[1];
                this.Name = (string)data[2];
                this.Flags = (int)data[3];
            }
        }
        public class Container
        {
            public int Kind, X, Y, SX, SY, ID, Type;
            public string Name;
            public Container(List<object> data)
            {
                if (data.Count() < 8)// throw an error
                    return;
                this.Kind = (int)data[0];
                this.X = (int)data[1];
                this.Y = (int)data[2];
                this.SX = (int)data[3];
                this.SY = (int)data[4];
                this.ID = (int)data[5];
                this.Type = (int)data[6];
                this.Name = (string)data[7];
            }
            public Container()
            {

            }
        }
        public class Skill
        {
            public int Normal, Real, Cap, Lock;
        }

        public class JournalEntry
        {
            public string Line;
            public int Col;


            public JournalEntry(string p1, int p2)
            {
                // TODO: Complete member initialization
                this.Line = p1;
                this.Col = p2;
            }
        }

        public class JournalScan
        {
            public int NewRef, Cnt;
        }
        public class PropertyInfo
        {
            public string Name;
            public string Info;
        }
        public class FoundItem
        {
            public int ID;
            public int Type;
            public int Kind;
            public int ContID;
            public int X, Y, Z;
            public int Stack, Rep, Col;
        }
        #endregion


        #region Event Macro
        public void EventMacro(int Par1, int Par2)
        {
            EventMacro(Par1, Par2, null);
        }
        public void EventMacro(int Par1, int Par2, string Par3)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Call");
            DLLWrap.PushStrVal(_uoHandle, "Macro");
            DLLWrap.PushInteger(_uoHandle, (int)Par1);
            DLLWrap.PushInteger(_uoHandle, (int)Par2);
            if (!string.IsNullOrEmpty(Par3))
                DLLWrap.PushStrVal(_uoHandle, (string)Par3);
            DLLWrap.Execute(_uoHandle);
        }
        #endregion

        #region SysMessage
        public void SysMessage(string msg)
        {
            SysMessage(msg, 0);
        }

        public void SysMessage(string msg, int hue)
        {
            _executeCommand(false, "SysMessage", new object[] { msg, hue });
        }

        #endregion

        #region Helpers
        private bool GetBoolean(string command)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Get");
            DLLWrap.PushStrVal(_uoHandle, command);
            var result = DLLWrap.Execute(_uoHandle);
            if (result == 0)
                return DLLWrap.GetBoolean(_uoHandle, 1);
            else
                return false;
        }

        private void SetBoolean(string command, Boolean value)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Set");
            DLLWrap.PushStrVal(_uoHandle, command);
            DLLWrap.PushBoolean(_uoHandle, value);
            DLLWrap.Execute(_uoHandle);
        }

        private int GetInt(string command)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Get");
            DLLWrap.PushStrVal(_uoHandle, command);
            var result = DLLWrap.Execute(_uoHandle);
            if (result == 0)
                return DLLWrap.GetInteger(_uoHandle, 1);
            else
                return 0;
        }

        private void SetInt(string command, int value)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Set");
            DLLWrap.PushStrVal(_uoHandle, command);
            DLLWrap.PushInteger(_uoHandle, value);
            DLLWrap.Execute(_uoHandle);
        }

        private string GetString(string command)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Get");
            DLLWrap.PushStrVal(_uoHandle, command);
            var _r = DLLWrap.Execute(_uoHandle);

            IntPtr sc = DLLWrap.GetString(_uoHandle, 1);
            return Marshal.PtrToStringAnsi(sc);
        }
        private void SetString(string command, string value)
        {
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Set");
            DLLWrap.PushStrVal(_uoHandle, command);
            DLLWrap.PushStrVal(_uoHandle, value);
            DLLWrap.Execute(_uoHandle);
        }

        //Executes a GameDLL command, Idea taken from jultima http://code.google.com/p/jultima/
        //A ja to ukrad z UOnet AHAHAHAHA
        private List<object> _executeCommand(bool ReturnResults, string CommandName, object[] args)
        {
            // Maybe return bool and results as an Out?
            List<object> Results = new List<object>();
            DLLWrap.SetTop(_uoHandle, 0);
            DLLWrap.PushStrVal(_uoHandle, "Call");
            DLLWrap.PushStrVal(_uoHandle, CommandName);
            foreach (var o in args)
            {
                if (o is Int32) // (o.GetType() == typeof(int))
                {
                    DLLWrap.PushInteger(_uoHandle, (int)o);
                }
                else if (o is string)
                {
                    DLLWrap.PushStrVal(_uoHandle, (string)o);
                }
                else if (o is bool)
                {
                    DLLWrap.PushBoolean(_uoHandle, (bool)o);
                }
            }
            if (DLLWrap.Execute(_uoHandle) != 0) { return null; }
            if (!ReturnResults) { return null; }
            int objectcnt = DLLWrap.GetTop(_uoHandle);
            for (int i = 1; i <= objectcnt; i++)
            {
                int gettype = DLLWrap.GetType(_uoHandle, 1);
                switch (gettype)
                {
                    case 1:
                        Results.Add(DLLWrap.GetBoolean(_uoHandle, i).ToString());

                        break;
                    case 3:
                        Results.Add(DLLWrap.GetInteger(_uoHandle, i).ToString());
                        break;
                    case 4:
                        Results.Add(DLLWrap.GetString(_uoHandle, i));
                        break;
                    default:
                        throw new NotImplementedException();
                    //break;
                }

            }
            return Results;
        }
        #endregion
    }

    public class Enums
    {
        public enum Skill
        {
            Anatomy = 1,
            AnimalLore = 2,
            AnimalTaming = 35,
            ArmsLore = 4,
            Begging = 6,
            Cartography = 12,
            DetectHidden = 14,
            Discordance = 15,
            EvalInt = 16,
            ForensicEval = 19,
            Hiding = 21,
            Inscription = 23,
            ItemIdentification = 3,
            Meditation = 46,
            Peacemaking = 9,
            Poisoning = 30,
            RemoveTrap = 48,
            SpiritSpeak = 32,
            Stealing = 33,
            Stealth = 47,
            TasteIdentification = 36,
            Tracking = 38,
            LastSkill = 0
        }
    }
}
